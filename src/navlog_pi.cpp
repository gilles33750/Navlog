
#include "navlog_pi.h"
#include <wx/log.h>
#include <wx/dcmemory.h>

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
    // Icône provisoire NavLog : carré bleu avec un N blanc
    m_panel_bitmap.Create(32, 32);

    wxMemoryDC dc;
    dc.SelectObject(m_panel_bitmap);

    dc.SetBackground(wxBrush(wxColour(20, 75, 130)));
    dc.Clear();

    dc.SetTextForeground(*wxWHITE);
    dc.SetFont(wxFont(
        20,
        wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD
    ));

    dc.DrawText("N", 8, 3);
    dc.SelectObject(wxNullBitmap);
}

{
}

NavLogPi::~NavLogPi() = default;

// Initialisation du plugin

int NavLogPi::Init()
{
    wxLogMessage("NavLog : initialisation");

    m_toolbar_id = InsertPlugInTool(
        "NavLog",
        &m_panel_bitmap,
        &m_panel_bitmap,
        wxITEM_NORMAL,
        "NavLog",
        "Ouvrir le journal de bord",
        nullptr,
        -1,
        0,
        this
    );

    return WANTS_NMEA_SENTENCES |
           WANTS_TOOLBAR_CALLBACK |
           INSTALLS_TOOLBAR_TOOL;
}

// Fermeture du plugin

bool NavLogPi::bool NavLogPi::DeInit()
{
    wxLogMessage("NavLog : fermeture");

    // Détruire la fenêtre NavLog si elle existe
    if (m_navlog_window != nullptr)
    {
        m_navlog_window->Destroy();
        m_navlog_window = nullptr;
    }

    // Supprimer le bouton de la barre d'outils
    if (m_toolbar_id != -1)
    {
        RemovePlugInTool(m_toolbar_id);
        m_toolbar_id = -1;
    }

    return true;
}
{
    wxLogMessage("NavLog : fermeture");

    if (m_toolbar_id != -1)
    {
        RemovePlugInTool(m_toolbar_id);
        m_toolbar_id = -1;
    }

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
    if (id != m_toolbar_id)
        return;

    // Créer la fenêtre uniquement au premier clic
    if (m_navlog_window == nullptr)
    {
        m_navlog_window = new wxFrame(
            nullptr,
            wxID_ANY,
            "NavLog - Journal de bord",
            wxDefaultPosition,
            wxSize(650, 450),
            wxDEFAULT_FRAME_STYLE
        );

        // Fermer visuellement la fenêtre sans la détruire
        m_navlog_window->Bind(
    wxEVT_CLOSE_WINDOW,
    [this](wxCloseEvent& event)
    {
        if (event.CanVeto())
        {
            m_navlog_window->Hide();
            event.Veto();
        }
        else
        {
            event.Skip();
        }
    }
);
    }

    // Afficher la fenêtre
    m_navlog_window->Show();
    m_navlog_window->Raise();
}

// Réception des phrases NMEA 0183

void NavLogPi::SetNMEASentence(wxString& sentence)
{
    wxLogMessage("NavLog NMEA : %s", sentence.c_str());
}
