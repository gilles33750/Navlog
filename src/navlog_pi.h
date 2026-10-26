
#ifndef NAVLOG_PI_H
#define NAVLOG_PI_H

#include "ocpn_plugin.h"
#include <wx/string.h>
#include <wx/bitmap.h>

class NavLogPi : public opencpn_plugin_118 {
public:
    explicit NavLogPi(void* ppimgr);
    ~NavLogPi() override;

    int Init() override;
    bool DeInit() override;

    int GetAPIVersionMajor() override;
    int GetAPIVersionMinor() override;

    int GetPlugInVersionMajor() override;
    int GetPlugInVersionMinor() override;
    int GetPlugInVersionPatch() override;
    int GetPlugInVersionPost() override;

    const char* GetPlugInVersionPre() override;
    const char* GetPlugInVersionBuild() override;

    wxBitmap* GetPlugInBitmap() override;

    wxString GetCommonName() override;
    wxString GetShortDescription() override;
    wxString GetLongDescription() override;

    int GetToolbarToolCount() override;
    void OnToolbarToolCallback(int id) override;

    void SetNMEASentence(wxString& sentence) override;

private:
    wxBitmap m_panel_bitmap;
};

#endif
