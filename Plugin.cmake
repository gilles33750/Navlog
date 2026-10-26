
# NavLog - Plugin OpenCPN
# Version 0.1.0
# Licence GPL-3.0-or-later

# Depots de publication (non utilises pour le prototype)
set(OCPN_TEST_REPO
    "gilles33750/navlog-alpha"
    CACHE STRING "Test repository"
)

set(OCPN_BETA_REPO
    "gilles33750/navlog-beta"
    CACHE STRING "Beta repository"
)

set(OCPN_RELEASE_REPO
    "gilles33750/navlog-prod"
    CACHE STRING "Release repository"
)

# Identification du plugin
set(PKG_NAME NavLog_pi)
set(PKG_VERSION 0.1.0)
set(PKG_PRERELEASE "")

set(DISPLAY_NAME NavLog)
set(PLUGIN_API_NAME NavLog)

set(PKG_SUMMARY "Journal de bord OpenCPN")

set(PKG_DESCRIPTION [=[
NavLog est un plugin de journal de bord pour OpenCPN.

Fonctionnalites prevues :
- Reception NMEA 0183
- Enregistrement SOG et COG
- Enregistrement du vent reel TWS et TWD
- Position GPS
- Historique des navigations
- Export CSV
]=])

set(PKG_AUTHOR "gilles33750")
set(PKG_IS_OPEN_SOURCE "yes")
set(PKG_HOMEPAGE "https://github.com/gilles33750/Navlog")
set(PKG_INFO_URL "https://github.com/gilles33750/Navlog")

# Fichiers sources C++
set(SRC
    src/navlog_pi.h
    src/navlog_pi.cpp
)

# API OpenCPN utilisee par notre prototype
set(PKG_API_LIB api-18)

# Initialisation supplementaire
macro(late_init)
endmacro()

# Bibliotheques supplementaires
macro(add_plugin_libraries)
endmacro()
