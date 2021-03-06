;NSIS Modern User Interface - Language File
;Compatible with Modern UI 1.67

;Language: Serbian (2074)
;Translation by Vladan Obradovic

;--------------------------------

!insertmacro MUI_LANGUAGEFILE_BEGIN "SERBIAN"

  !define MUI_LANGNAME "Serbian" ;Use only ASCII characters (if this is not possible, use the English name)

  !define MUI_TEXT_WELCOME_INFO_TITLE "Dobro do�li u instalaciju programa $(^NameDA)"
  !define MUI_TEXT_WELCOME_INFO_TEXT "Program �e instalirati $(^NameDA)-u na Va� ra�unar.\r\n\r\nPreporu�uje se da se zatvore sve aplikacije pre odpo�injanja Instalacije. Time �e se omogu�iti Instalaciji da a�urira potrebne sistemska datoteke bez potrebe za ponovnim pokretanjem va�eg ra�unara.\r\n\r\n$_CLICK"

  !define MUI_TEXT_LICENSE_TITLE "Licenca"
  !define MUI_TEXT_LICENSE_SUBTITLE "Pro�itajte licencu pre instalacije $(^NameDA)-e."
  !define MUI_INNERTEXT_LICENSE_TOP "Pritisnite Page Down da vidite ostatak licence."
  !define MUI_INNERTEXT_LICENSE_BOTTOM "Ukoliko prihvatate uslove licence, odaberite Prihvatam za nastavak. Licenca se mora prihvatiti ukolko �elite da instalirate $(^NameDA)-u."
  !define MUI_INNERTEXT_LICENSE_BOTTOM_CHECKBOX "Ako prihvatate uslove licence, kliknite na check box ispod. Licenca se mora prihvatiti ukolko �elite da instalirate $(^NameDA)-u.  $_CLICK"
  !define MUI_INNERTEXT_LICENSE_BOTTOM_RADIOBUTTONS "Ako prihvatate uslove licence, odaberite prvu opciju ispod. Licenca se mora prihvatiti ukolko �elite da instalirate $(^NameDA)-u. $_CLICK"

  !define MUI_TEXT_COMPONENTS_TITLE "Odaberite komponente"
  !define MUI_TEXT_COMPONENTS_SUBTITLE "Odaberite koje komponente $(^NameDA)-e �elite da instalirate."
  !define MUI_INNERTEXT_COMPONENTS_DESCRIPTION_TITLE "Opis"
  !define MUI_INNERTEXT_COMPONENTS_DESCRIPTION_INFO "Pozicionirajte se mi�em iznad komponente da vidite njen opis."

  !define MUI_TEXT_DIRECTORY_TITLE "Odaberite instalacioni direktorijum"
  !define MUI_TEXT_DIRECTORY_SUBTITLE "Odaberite direktorijum u koji �elite da instalirate $(^NameDA)-u."

  !define MUI_TEXT_INSTALLING_TITLE "Instalacija"
  !define MUI_TEXT_INSTALLING_SUBTITLE "Molim Vas pri�ekajte instalacija $(^NameDA)-e je u toku."

  !define MUI_TEXT_FINISH_TITLE "Instalacija zavr�ena"
  !define MUI_TEXT_FINISH_SUBTITLE "Instalacija je uspe�no zavr�ena."

  !define MUI_TEXT_ABORT_TITLE "Instalacija prekinuta"
  !define MUI_TEXT_ABORT_SUBTITLE "Setup nije uspe�no zavr�en."

  !define MUI_BUTTONTEXT_FINISH "&Zavr�i"
  !define MUI_TEXT_FINISH_INFO_TITLE "Zavr�avanje $(^NameDA) Instalacije"
  !define MUI_TEXT_FINISH_INFO_TEXT "$(^NameDA) je instalirana na Va� ra�unar.\r\n\r\nKliknite Zavr�i da zatvorite instalacioni program."
  !define MUI_TEXT_FINISH_INFO_REBOOT "Va� ra�unar je potrebno restartovati da bi instalacija $(^NameDA)-e bila kompletirana. �elite li da ra�unar restartujete odmah?"
  !define MUI_TEXT_FINISH_REBOOTNOW "Restartuj odmah"
  !define MUI_TEXT_FINISH_REBOOTLATER "�elim ga ru�no restartovati kasnije"
  !define MUI_TEXT_FINISH_RUN "Pokreni $(^NameDA)-u"
  !define MUI_TEXT_FINISH_SHOWREADME "Poka�i Readme"

  !define MUI_TEXT_STARTMENU_TITLE "Odaberite Direktorijum u Start Meniju"
  !define MUI_TEXT_STARTMENU_SUBTITLE "Odaberite direktorijum u Start Meniju za programske shortcutove."
  !define MUI_INNERTEXT_STARTMENU_TOP "Odaberite direktorijum u Start Meniju u kom �elite napraviti programske shortcutove. Tako�e, mo�ete uneti ime da bi se naparavio novi direktorijum."
  !define MUI_INNERTEXT_STARTMENU_CHECKBOX "Nemoj praviti shortcut-ove"

  !define MUI_TEXT_ABORTWARNING "Da li ste sigurni da �elite prekinuti $(^Name) Instalaciju?"


  !define MUI_UNTEXT_WELCOME_INFO_TITLE "Dobrodo�li u postupak deinstalacije programa $(^NameDA)"
  !define MUI_UNTEXT_WELCOME_INFO_TEXT "Ovaj �arobnjak �e Vas provesti kroz postupak deinstalacije programa $(^NameDA).\r\n\r\nPre samog po�etka, molim Vas zatvorite program $(^NameDA) ukoliko je otvoren.\r\n\r\n$_CLICK"

  !define MUI_UNTEXT_CONFIRM_TITLE "Deinstalacija programa $(^NameDA)"
  !define MUI_UNTEXT_CONFIRM_SUBTITLE "Program $(^NameDA) �e biti deinstaliran s Va�eg ra�unara."

  !define MUI_UNTEXT_LICENSE_TITLE "Licenca"  
  !define MUI_UNTEXT_LICENSE_SUBTITLE "Pro�itajte licencu pre deinstalacije programa $(^NameDA)."
  !define MUI_UNINNERTEXT_LICENSE_BOTTOM "Ukoliko prihvatate uslove licence, odaberite 'Prihvatam' za nastavak. Morate prihvatiti licencu za deinstalaciju programa $(^NameDA)."
  !define MUI_UNINNERTEXT_LICENSE_BOTTOM_CHECKBOX "Ukoliko prihvatate uslove iz licence, obele�ite kvadrati� ispod. Morate prihvatiti licencu za deinstalaciju programa $(^NameDA). $_CLICK"
  !define MUI_UNINNERTEXT_LICENSE_BOTTOM_RADIOBUTTONS "Ukoliko prihvatate uslove iz licence, odaberite prvu opciju ispod. Morate prihvatiti licencu za deinstalaciju programa $(^NameDA). $_CLICK"

  !define MUI_UNTEXT_COMPONENTS_TITLE "Izbor komponenti"
  !define MUI_UNTEXT_COMPONENTS_SUBTITLE "Odaberite koje komponente programa $(^NameDA) �elite deinstalirati."

  !define MUI_UNTEXT_DIRECTORY_TITLE "Odaberite direktorijum koji se deinstalira"
  !define MUI_UNTEXT_DIRECTORY_SUBTITLE "Odaberite programsku grupu iz koje �elite deinstalirati program $(^NameDA)."

  !define MUI_UNTEXT_UNINSTALLING_TITLE "Deinstalacija"
  !define MUI_UNTEXT_UNINSTALLING_SUBTITLE "Pri�ekajte zavr�etak deinstalacije programa $(^NameDA)."

  !define MUI_UNTEXT_FINISH_TITLE "Zavr�eno"
  !define MUI_UNTEXT_FINISH_SUBTITLE "Deinstalacija je uspe�no zavr�ena."
  
  !define MUI_UNTEXT_ABORT_TITLE "Deinstalacija prekinuta"
  !define MUI_UNTEXT_ABORT_SUBTITLE "Deinstalacija nije uspe�no zavr�ena."

  !define MUI_UNTEXT_FINISH_INFO_TITLE "Kraj deinstalacije programa $(^NameDA)"
  !define MUI_UNTEXT_FINISH_INFO_TEXT "Program $(^NameDA) je deinstaliran s Va�eg ra�unara.\r\n\r\nOdaberite 'Kraj' za zatvaranje ove deinstalacije."

  !define MUI_UNTEXT_ABORTWARNING "Jeste li sigurni da �elite prekinuti deinstalaciju programa $(^Name)?"  

!insertmacro MUI_LANGUAGEFILE_END