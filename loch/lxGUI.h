/**
 * @file lxGUI.h
 * Loch user interface.
 */
  
/* Copyright (C) 2004 Stacho Mudrak
 * 
 * $Date: $
 * $RCSfile: $
 * $Revision: $
 *
 * -------------------------------------------------------------------- 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * -------------------------------------------------------------------- 
 */

#ifndef lxGUI_h
#define lxGUI_h

// Standard libraries
#ifndef LXDEPCHECK
#include <wx/wx.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/docview.h>
#endif  
//LXDEPCHECK - standart libraries


#include "lxGLC.h"

enum {
  LXMENU_CAMERA_ADJUST = 1000,
  LXMENU_CAMERA_ROTCW,
  LXMENU_CAMERA_ROTCCW,
  LXMENU_CAMERA_UPPER,
  LXMENU_CAMERA_LOWER,
  LXMENU_CAMERA_UP,
  LXMENU_CAMERA_DOWN,
  LXMENU_CAMERA_LEFT,
  LXMENU_CAMERA_RIGHT,
  LXMENU_CAMERA_ZOOMIN,
  LXMENU_CAMERA_ZOOMOUT,
  LXMENU_CAMERA_ORIENT,
  LXMENU_CAMERA_ORIENT_HOME,
  LXMENU_CAMERA_ORIENT_PLAN,
  LXMENU_CAMERA_ORIENT_PROFILE,
  LXMENU_CAMERA_ORIENT_NORTH,
  LXMENU_CAMERA_ORIENT_SOUTH,
  LXMENU_CAMERA_ORIENT_EAST,
  LXMENU_CAMERA_ORIENT_WEST,
  LXMENU_CAMERA_EXTENDS,
  LXMENU_CAMERA_DEFAULTS,
  LXMENU_CAMERA_PERSP,
  LXMENU_CAMERA_AUTOROTATE,
  LXMENU_CAMERA_LOCKROT,
	LXMENU_VIEW,
  LXMENU_VIEW_FULLSCREEN,
  LXMENU_VIEW_MODELSTP,
  LXMENU_VIEW_VIEWPOINTSTP,
  LXMENU_TOOLS_OPTIONS,
	LXMENU_VIEWEND,
  LXMENU_EDIT_UNDO,
  LXMENU_EDIT_REDO,
  LXMENU_FILE_OPEN,
  LXMENU_FILE_RELOAD,
  LXMENU_FILE_RENDER,
  LXMENU_FILE_RENDER_SETUP,
  LXMENU_HELP_CONTENTS,
  LXMENU_HELP_CONTROL,
  LXMENU_HELP_RENDERING,
  LXMENU_HELP_BUGS,
  LXMENU_HELP_ABOUT,
	LXTB,
	LXTB_OPEN,
	LXTB_RELOAD,
	LXTB_RENDER,
	LXTB_RENDER_SETUP,
	LXTB_VIEWPOINT,
	LXTB_PERSP,
	LXTB_ROTATION,
	LXTB_LOCKROT,
  LXTB_PLAN,
  LXTB_PROFILE,
	LXTB_FIT,
  LXTB_HOME,
	LXTB_FULLSCREEN,
	LXTB_STEREO,
	LXTB_VIEWSTP,
	LXTB_SCENESTP,
  LXTB_VISCENTERLINE,
  LXTB_VISWALLS,
  LXTB_VISSURFACE,
  LXTB_VISBBOX,
  LXTB_VISINDS,
	LXTBEND,
};


enum {
  LXWALLS_INTERP_NONE,
  LXWALLS_INTERP_ALL_ONLY,
  LXWALLS_INTERP_MISSING,
};


class lxFrame: public wxFrame
{

  public:

    lxGLCanvas * canvas;
    wxString m_fileName, m_fileDir;
    int m_fileType;
    
    struct lxData * data;
    struct lxSetup * setup;
    struct lxRenderData * m_renderData;

    class lxModelSetupDlg * m_modelSetupDlg;
    bool m_modelSetupDlgOn;

		class lxViewpointSetupDlg * m_viewpointSetupDlg;
    bool m_viewpointSetupDlgOn;

    wxMenuBar * m_menuBar;
		wxToolBar * m_toolBar;
		wxMenu * m_viewpointMenu, * m_toolMenu;
    wxAcceleratorTable m_menuAccelTable;

    wxFileConfig * m_fileConfig;
    wxFileHistory * m_fileHistory;
    wxString m_iniDirectory;

    int m_iniStereoGlasses;
    int m_iniStereoGlassesLast;
    long m_iniWallsInterpolate;

    class lxApp * m_app;

    class wxHelpController * m_helpController;

    lxFrame(class lxApp * app, const wxString& title, const wxPoint& pos,
      const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
      
    virtual ~lxFrame(); 
    void OnExit(wxCommandEvent& event);

    void OnAll(wxCommandEvent& event);
    void OnMenuCameraMove(wxCommandEvent& event);
    void OnMenuCameraOrient(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnMove(wxMoveEvent& event);
		
    void TogglePerspective();
    void ToggleStereo();
    void ToggleStereoBW();
		void ToggleRotation();
		void ToggleRotLock();
    void ToggleFullScreen();
    void ToggleModelSetup();
    void ToggleViewpointSetup();

    void ToggleVisibilityCenterline();
    void ToggleVisibilityCenterlineCave();
    void ToggleVisibilityCenterlineSurface();
    void ToggleVisibilitySurface();
    void ToggleVisibilityWalls();
    void ToggleVisibilityLabels();
    void ToggleVisibilityBBox();
    void ToggleVisibilityGrid();
    void ToggleVisibilityIndicators();

    void SetColorMode(int);
    void DetectFileType();
    void ToggleColorsApplyCenterline();
    void ToggleColorsApplyWalls();

    void ToggleSurfaceTexture();
    void ToggleSurfaceTransparency();

    void ToggleWallsTransparency();

    void SetupUpdate();
    void SetupApply();
    void OpenFile(const wxString & fName);

    void ReloadData();
		void UpdateM2TB();

    DECLARE_EVENT_TABLE()
    
}; // lxFrame



class lxApp: public wxApp
{

  public:
  
    class lxFrame * frame;

    wxLocale m_locale;
    wxFileName m_path;
  
    bool OnInit();
    
}; // lxApp

#endif

