#pragma once

#include <string>
#include <vector>
#include <thread>

namespace W32Util
{
	std::string BrowseForFolder(HWND parent, const char *title);
	std::string BrowseForFolder(HWND parent, const wchar_t *title);
	bool BrowseForFileName (bool _bLoad, HWND _hParent, const wchar_t*_pTitle,
		const wchar_t *_pInitialFolder,const wchar_t *_pFilter,const wchar_t*_pExtension, 
		std::string& _strFileName);
	std::vector<std::string> BrowseForFileNameMultiSelect(bool _bLoad, HWND _hParent, const wchar_t*_pTitle,
		const wchar_t*_pInitialFolder,const wchar_t*_pFilter,const wchar_t*_pExtension);

	std::string UserDocumentsPath();

	bool CreateDesktopShortcut(const std::string &argumentPath, std::string gameTitle);
}
