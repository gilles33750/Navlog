
#include "navlog_pi.h"

#include <wx/log.h>

// Fonctions utilisées par OpenCPN pour créer et détruire le plugin.

extern "C" __declspec(dllexport) opencpn_plugin* create_pi(void* ppimgr)
{
    return new NavLogPi(ppimgr);
}

extern "C" __declspec(dllexport) void destroy_pi(opencpn_plugin* plugin)
{
    delete plugin;
}

// Constructeur et destructeur

NavLogPi::NavLogPi(void* ppimgr)
    : opencpn_plugin_118(ppimgr)
{
}

NavLogPi::~NavLogPi() = default;

// Initialisation du plugin

int NavLogPi::Init()
{
    wxLogMessage("NavLog : initialisation");

    return WANTS_NMEA_SENTENCES;
}

// Fermeture du plugin

bool NavLogPi::DeInit()
{
    wxLogMessage("NavLog : fermeture");
    return true;
}

// Version de l'API OpenCPN

int NavLogPi::GetAPIVersionMajor()
{
    return 1;
}

int NavLogPi::GetAPIVersionMinor()
{
    return 18;
}

// Version de NavLog

int NavLogPi::GetPlugInVersionMajor()
{
    return 0;
}

int NavLogPi::GetPlugInVersionMinor()
{
    return 1;
}

int NavLogPi::GetPlugInVersionPatch()
{
    return 0;
}

int NavLogPi::GetPlugInVersionPost()
{
    return 0;
}

const char* NavLogPi::GetPlugInVersionPre()
{
    return "";
}

const char* NavLogPi::GetPlugInVersionBuild()
{
    return "";
}

// Informations affichées dans OpenCPN

wxBitmap* NavLogPi::GetPlugInBitmap()
{
    return &m_panel_bitmap;
}

wxString NavLogPi::GetCommonName()
{
    return "NavLog";
}

wxString NavLogPi::GetShortDescription()
{
    return "Journal de bord automatique";
}

wxString NavLogPi::GetLongDescription()
{
    return "Enregistrement des donnees de navigation NMEA 0183.";
}

// Barre d'outils : aucun bouton pour cette première version

int NavLogPi::GetToolbarToolCount()
{
    return 0;
}

void NavLogPi::OnToolbarToolCallback(int id)
{
    (void)id;
}

// Réception des phrases NMEA 0183

void NavLogPi::SetNMEASentence(wxString& sentence)
{
    wxLogMessage("NavLog NMEA : %s", sentence.c_str());
}
