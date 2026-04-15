Outfile "WireGuardQt-setup.exe"
InstallDir "$PROGRAMFILES\WireGuardQt"

Page directory
Page instfiles

Section
    SetOutPath "$INSTDIR"
    File /r "app\*.*"

    CreateShortcut "$DESKTOP\WireGuardQt.lnk" "$INSTDIR\WireGuardQt.exe"
SectionEnd
