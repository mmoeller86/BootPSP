// Copyright (C) 2003 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#pragma once

#include <atomic>

#include "LogManager.h"

#ifdef _WIN32
#include "CommonWindows.h"
#endif

class ConsoleListener : public LogListener {
public:
	ConsoleListener();
	~ConsoleListener();

	void Init(bool AutoOpen = true, int Width = 200, int Height = 100, const char * Name = "DebugConsole (PPSSPP)");
	void Open();
	void UpdateHandle();
	void Close();
	bool IsOpen();
	void LetterSpace(int Width, int Height);
	void BufferWidthHeight(int BufferWidth, int BufferHeight, int ScreenWidth, int ScreenHeight, bool BufferFirst);
	void PixelSpace(int Left, int Top, int Width, int Height, bool);
#if defined(USING_WIN_UI)
	COORD GetCoordinates(int BytesRead, int BufferWidth);
#endif
	void Log(const LogMessage &message) override;
	void ClearScreen(bool Cursor = true);

	void Show(bool bShow);
	bool Hidden() const { return bHidden; }

private:
#if defined(USING_WIN_UI)
	HWND hWnd;
	HANDLE hConsole;

	static unsigned int WINAPI RunThread(void *lpParam);
	void LogWriterThread();
	void SendToThread(LogLevel Level, const char *Text);
	void WriteToConsole(LogLevel Level, const char *Text, size_t Len);

	static int refCount;
	static HANDLE hThread;
	static HANDLE hTriggerEvent;
	static CRITICAL_SECTION criticalSection;

	static char *logPending;
	static std::atomic<uint32_t> logPendingReadPos;
	static std::atomic<uint32_t> logPendingWritePos;

	int openWidth_ = 0;
	int openHeight_ = 0;
	std::wstring title_;
#endif
	bool bHidden;
	bool bUseColor;
};
