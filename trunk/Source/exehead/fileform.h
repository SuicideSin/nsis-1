#include "config.h"

#ifndef _FILEFORM_H_
#define _FILEFORM_H_


// stored in file:
// exehead (~34k)
// firstheader (~28 bytes)
// hdrinfo (4 bytes describing length/compression)::
//   (if install)
//     header (~228 bytes)
//     sections (20 bytes each)
//   (if uninstall)
//     uninstall_header (~116 bytes)
//   entries (24 bytes each)
//   string table
// datablock
// (hdrinfo+datablock is at least 512 bytes if CRC enabled)
// CRC (optional - 4 bytes)


#define MAX_ENTRY_OFFSETS 5


// if you want people to not be able to decompile your installers as easily,
// reorder the lines following EW_INVALID_OPCODE randomly.

enum
{
  EW_INVALID_OPCODE,    // zero is invalid. useful for catching errors. (otherwise an all zeroes instruction does nothing, which is
                        // easily ignored but means something is wrong.
  EW_RET,               // return from function call
  EW_NOP,               // Nop/Jump, do nothing: 1, [?new address+1:advance one]
  EW_ABORT,             // Abort: 1 [status]
  EW_QUIT,              // Quit: 0
  EW_CALL,              // Call: 1 [new address+1]
  EW_UPDATETEXT,        // Update status text: 2 [update str, ui_st_updateflag=?ui_st_updateflag:this]
  EW_SLEEP,             // Sleep: 1 [sleep time in milliseconds]
  EW_SETSFCONTEXT,      // SetShellVarContext: 1: [isAll]
  EW_HIDEWINDOW,        // HideWindow: 0
  EW_BRINGTOFRONT,      // BringToFront: 0
  EW_SETWINDOWCLOSE,    // SetWindowClose: 1 [0: no window close at end, 1: window close at end]
  EW_CHDETAILSVIEW,     // SetDetailsView: 2 [listaction,buttonaction]
  EW_SETFILEATTRIBUTES, // SetFileAttributes: 2 [filename, attributes]
  EW_CREATEDIR,         // Create directory: 2, [path, ?update$INSTDIR]
  EW_IFFILEEXISTS,      // IfFileExists: 3, [file name, jump amount if exists, jump amount if not exists]
  EW_IFERRORS,           //a IfErrors: 3 [jump if error, jump if not error, new_erflag]
  EW_RENAME,            // Rename: 3 [old, new, rebootok]
  EW_GETFULLPATHNAME,   // GetFullPathName: 2 [output, input, ?lfn:sfn]
  EW_SEARCHPATH,        // SearchPath: 2 [output, filename]
  EW_GETTEMPFILENAME,   // GetTempFileName: 1 [output]
  EW_EXTRACTFILE,       // File to extract: 5,[overwriteflag, output filename, compressed filedata, filedatetimelow, filedatetimehigh]
                        //  overwriteflag: 0x1 = no. 0x0=force, 0x2=try, 0x3=if date is newer
  EW_DELETEFILE,        // Delete File: 2, [filename, rebootok]
  EW_MESSAGEBOX,        // MessageBox: 5,[MB_flags,text,retv1:retv2,moveonretv1:moveonretv2]
  EW_RMDIR,             // RMDir: 2 [path, recursiveflag]
  EW_STRLEN,            // StrLen: 2 [output, input]
  EW_ASSIGNVAR,         // Assign: 4 [variable (0-9) to assign, string to assign, maxlen, startpos]
  EW_STRCMP,            // StrCmp: 4 [str1, str2, jump_if_equal, jump_if_not_equal] (case-insensitive)
  EW_READENVSTR,        // ReadEnvStr/ExpandEnvStrings: 3 [output, string_with_env_variables, IsRead]
  EW_INTCMP,            // IntCmp: 5 [val1, val2, equal, val1<val2, val1>val2]
  EW_INTCMPU,           // IntCmpU: 5 [val1, val2, equal, val1<val2, val1>val2]
  EW_INTOP,             // IntOp: 4 [output, input1, input2, op] where op: 0=add, 1=sub, 2=mul, 3=div, 4=bor, 5=band, 6=bxor, 7=bnot input1, 8=lnot input1, 9=lor, 10=land], 11=1%2
  EW_INTFMT,            // IntFmt: [output, format, input]
  EW_PUSHPOP,           // Push/Pop/Exchange: 3 [variable/string, ?pop:push, ?exch]

  EW_FINDWINDOW,        // FindWindow: 5, [outputvar,window class,window name, window_parent, window_after]
  EW_SENDMESSAGE,       // SendMessage: 5 [output, hwnd, msg, lparam, wparam]
  EW_ISWINDOW,          // IsWindow: 3 [hwnd, jump_if_window, jump_if_notwindow]
  EW_SETDLGITEMTEXT,    // SetDlgItemText: 3 [outer? item_id, text]

  EW_SHELLEXEC,         // ShellExecute program: 4, [shell action, complete commandline, parameters, showwindow]

  EW_EXECUTE,           // Execute program: 3,[complete command line,waitflag,>=0?output errorcode]

  EW_GETFILETIME,       // GetFileTime; 3 [file highout lowout]

  EW_GETDLLVERSION,     // GetDLLVersion: 3 [file highout lowout]

  EW_REGISTERDLL,       // Register DLL: 3,[DLL file name, string ptr of function to call, text to put in display (<0 if none/pass parms)]

  EW_CREATESHORTCUT,    // Make Shortcut: 5, [link file, target file, parameters, icon file, iconindex|show mode<<8|hotkey<<16]

  EW_COPYFILES,         // CopyFiles: 3 [source mask, destination location, flags]

  EW_REBOOT,            // Reboot: 1 [0xbadf00d]
  EW_IFREBOOTFLAG,      // IfRebootFlag: 2 [if reboot flag set, if not reboot flag]
  EW_SETREBOOTFLAG,     // SetRebootFlag: 1 [new value]

  EW_WRITEINI,          // Write INI String: 4, [Section, Name, Value, INI File]
  EW_READINISTR,        // ReadINIStr: 4 [output, section, name, ini_file]

  EW_DELREG,            // DeleteRegValue/DeleteRegKey: 4, [root key(int), KeyName, ValueName, delkeyonlyifempty]. ValueName is -1 if delete key
  EW_WRITEREG,          // Write Registry value: 5, [RootKey(int),KeyName,ItemName,ItemData,typelen]
                        //  typelen=1 for str, 2 for dword, 3 for binary, 0 for expanded str
  EW_READREGSTR,        // ReadRegStr: 5 [output, rootkey(int), keyname, itemname, ==1?int::str]
  EW_REGENUM,           // RegEnum: 5 [output, rootkey, keyname, index, ?key:value]

  EW_FCLOSE,            // FileClose: 1 [handle]
  EW_FOPEN,             // FileOpen: 4  [name, openmode, createmode, outputhandle]
  EW_FPUTS,             // FileWrite: 3 [handle, string, ?int:string]
  EW_FGETS,             // FileRead: 4  [handle, output, maxlen, ?getchar:gets]
  EW_FSEEK,             // FileSeek: 4  [handle, offset, mode, >=0?positionoutput]

  EW_FINDCLOSE,         // FindClose: 1 [handle]
  EW_FINDNEXT,          // FindNext: 2  [output, handle]
  EW_FINDFIRST,         // FindFirst: 2 [filespec, output, handleoutput]

  EW_WRITEUNINSTALLER,  // WriteUninstaller: 1 [name]

  EW_LOG,               // LogText: 2 [0, text] / LogSet: [1, logstate]

  EW_SECTIONSET,        // SectionSetText:    3: [idx, 0, text]
                        // SectionGetText:    3: [idx, 1, output]
                        // SectionSetFlags:   3: [idx, 2, flags]
                        // SectionGetFlags:   3: [idx, 3, output]

  EW_SETBRANDINGIMAGE,  // SetBrandingImage:  1: [Bitmap file]

  // instructions not actually implemented in exehead, but used in compiler.
  EW_GETLABELADDR,      // both of these get converted to EW_ASSIGNVAR
  EW_GETFUNCTIONADDR,

  EW_PLUGINCOMMANDPREP

};


// used for section->default_state
#define DFS_SET 0x80000000
#define DFS_RO  0x40000000



typedef struct
{
  int flags; // &1=CRC, &2=uninstall, &4=silent
  int siginfo;  // FH_SIG

  int nsinst[3]; // FH_INT1,FH_INT2,FH_INT3

  // these point to the header+sections+entries+stringtable in the datablock
  int length_of_header;

  // this specifies the length of all the data (including the firstheader and CRC)
  int length_of_all_following_data;
} firstheader;

// Strings common to both installers and uninstallers
typedef struct
{
  WORD lang_id;

  // unprocessed strings
  int branding;
  int cancelbutton;
  int showdetailsbutton;
  int completed;
  int closebutton;   // "Close"
  int name; // name of installer

  // processed strings
  int caption; // name of installer + " Setup" or whatever.
  int subcaptions[5];

#ifdef NSIS_SUPPORT_FILE
  int fileerrtext;
#endif

#if defined(NSIS_SUPPORT_DELETE) || defined(NSIS_SUPPORT_RMDIR) || defined(NSIS_SUPPORT_FILE)
  int cant_write;
#endif
#ifdef NSIS_SUPPORT_RMDIR
  int remove_dir;
#endif
#ifdef NSIS_SUPPORT_COPYFILES
  int copy_failed;
  int copy_to;
#endif
#ifdef NSIS_SUPPORT_ACTIVEXREG
  int symbol_not_found;
  int could_not_load;
  int no_ole;
  // not used anywhere - int err_reg_dll;
#endif
#ifdef NSIS_SUPPORT_CREATESHORTCUT
  int create_shortcut;
  int err_creating_shortcut;
#endif
#ifdef NSIS_SUPPORT_DELETE
  int del_file;
#ifdef NSIS_SUPPORT_MOVEONREBOOT
  int del_on_reboot;
#endif
#endif
#ifdef NSIS_CONFIG_UNINSTALL_SUPPORT
  int created_uninst;
  int err_creating;
#endif
#ifdef NSIS_SUPPORT_SHELLEXECUTE
  int exec_shell;
#endif
#ifdef NSIS_SUPPORT_EXECUTE
  int exec;
#endif
#ifdef NSIS_SUPPORT_MOVEONREBOOT
  int rename_on_reboot;
#endif
#ifdef NSIS_SUPPORT_RENAME
  int rename;
#endif
#ifdef NSIS_SUPPORT_FILE
  int extract;
  int err_writing;
  int err_decompressing;
  int skipped;
#endif
  int inst_corrupted;
  int output_dir;
  int create_dir;
} common_strings;

// Settings common to both installers and uninstallers
typedef struct
{
  int str_tables; // offset to tables array

  int num_entries; // total number of entries

#ifdef NSIS_SUPPORT_BGBG
  int bg_color1, bg_color2, bg_textcolor;
#endif
  int lb_bg, lb_fg, license_bg;

#ifdef NSIS_SUPPORT_CODECALLBACKS
  // .on* calls
  int code_onInit;
  int code_onInstSuccess;
  int code_onInstFailed;
  int code_onUserAbort;
  int code_onNextPage;
#endif//NSIS_SUPPORT_CODECALLBACKS

  char show_details;
  char progress_flags;
#ifdef NSIS_CONFIG_SILENT_SUPPORT
  char silent_install;
#endif//NSIS_CONFIG_SILENT_SUPPORT
  // additional flags
  char misc_flags; // auto_close=&1, no_show_dirpage=&2, no_show_icon&4, no_rootdir&8;

  // Added by Amir Szekely 6th August 2002
  // Adds the ability to make the inner text show up in a dialog item in the outer dialog.
  WORD intro_text_id;

} common_header;

// Strings specific to installers
typedef struct
{
  WORD lang_id;

  // these first strings are literals (should not be encoded)
  int backbutton;
  int nextbutton;
  int browse; // "Browse..."
  int installbutton; // "Install"
  int spacerequired; // "Space required: "
  int spaceavailable; // "Space available: "
  int custom;  // Custom
  int text; // directory page text
  int dirsubtext; // directory text2
#ifdef NSIS_CONFIG_COMPONENTPAGE
  int componenttext; // component page text
  int componentsubtext[2];
#endif
#ifdef NSIS_CONFIG_LICENSEPAGE
  int licensetext; // license page text
  int licensedata; // license text
  int licensebutton; // license button text
#endif//NSIS_CONFIG_LICENSEPAGE
} installer_strings;

// Settings specific to installers
typedef struct
{
  // common settings
  common_header common;

  int str_tables_num; // number of strings tables in array
  int str_tables; // offset to tables array

  int install_reg_rootkey, install_reg_key_ptr, install_reg_value_ptr;

#ifdef NSIS_CONFIG_COMPONENTPAGE
  int install_types_ptr[NSIS_MAX_INST_TYPES]; // -1 if not used. can describe as lite, normal, full, etc.
#endif

#ifdef NSIS_CONFIG_LICENSEPAGE
  int license_bg; // license background color
#endif//NSIS_CONFIG_LICENSEPAGE

  // below here, the strings are processed (can have variables etc)
  int install_directory_ptr; // default install dir.

#ifdef NSIS_CONFIG_UNINSTALL_SUPPORT
  int uninstdata_offset; // -1 if no uninst data.
  int uninsticon_size;
#endif

#ifdef NSIS_CONFIG_COMPONENTPAGE
  int no_custom_instmode_flag;
#endif

  int num_sections; // total number of sections

#ifdef NSIS_SUPPORT_CODECALLBACKS
  // .on* calls
  int code_onPrevPage;
  int code_onVerifyInstDir;
#ifdef NSIS_CONFIG_COMPONENTPAGE
  int code_onSelChange;
#endif//NSIS_CONFIG_COMPONENTPAGE
#endif//NSIS_SUPPORT_CODECALLBACKS

  // Added by Amir Szekely 6th August 2002
  // Adds the ability to make the inner text show up in a dialog item in the outer dialog.
  WORD space_avail_id;
  WORD space_req_id;
  WORD dir_subtext_id;
  WORD com_subtext1_id;
  WORD com_subtext2_id;

} header;

// Strings specific to uninstallers
typedef struct
{
  WORD lang_id;

  // unprocessed strings
  int uninstbutton;
  int uninstalltext;
  int uninstalltext2;
} uninstall_strings;

// Settings specific to uninstallers
typedef struct
{
  // common settings
  common_header common;

  int str_tables_num; // number of strings tables in array
  int str_tables; // offset to tables array

  int code;
  int code_size;

  // Added by Amir Szekely 6th August 2002
  // Adds the ability to make the inner text show up in a dialog item in the outer dialog.
  WORD uninst_subtext_id;

} uninstall_header;

typedef struct
{
  int name_ptr; // '' for non-optional components
  int default_state; // bits 0-30 set for each of the different install_types, if any.
                      // DFS_SET and DFS_RO can be set too
  int code;
  int code_size;
  int size_kb;
  int expand;
} section;


typedef struct
{
  int which;
  int offsets[MAX_ENTRY_OFFSETS];	// count and meaning of offsets depend on 'which'
} entry;


#define FH_FLAGS_MASK 15
#define FH_FLAGS_CRC 1
#define FH_FLAGS_UNINSTALL 2
#ifdef NSIS_CONFIG_SILENT_SUPPORT
#define FH_FLAGS_SILENT 4
#endif
// Added by Amir Szekely 23rd July 2002
#define FH_FLAGS_FORCE_CRC 8

#define FH_SIG 0xDEADBEEF

// neato surprise signature that goes in firstheader. :)
#define FH_INT1 0x6C6C754E
#define FH_INT2 0x74666F73
#define FH_INT3 0x74736E49

// the following are only used/implemented in exehead, not makensis.

int isheader(firstheader *h); // returns 0 on not header, length_of_datablock on success

// returns nonzero on error
// returns 0 on success
// on success, m_header will be set to a pointer that should eventually be GlobalFree()'d.
// (or m_uninstheader)
int loadHeaders(void);

extern HANDLE g_db_hFile;
extern int g_quit_flag;

const char *GetStringFromStringTab(int offs);
int GetCompressedDataFromDataBlock(int offset, HANDLE hFileOut);
int GetCompressedDataFromDataBlockToMemory(int offset, char *out, int out_len);

// $0..$9, $INSTDIR, etc are encoded as ASCII bytes starting from this value.
#define VAR_CODES_START (256 - 36)


#endif //_FILEFORM_H_
