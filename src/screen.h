#ifndef SCREEN__H
#define SCREEN__H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <coreinit/memory.h>
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_udp.h>
#include <coreinit/screen.h>
#include <coreinit/memheap.h>
#include <coreinit/cache.h>
#include <coreinit/memfrmheap.h>
#include <coreinit/memory.h>

class WiiUScreen
{
public:
	WiiUScreen();
	~WiiUScreen();
	
	void DrawText(const char *text);
	void DrawTextf(const char *text, ...);
	void DrawTextLine(int line, const char *text);
	void FlushBuffers();

	void StartFrame();
	void EndFrame();

	bool FlushEveryDraw = false;

	int BufferSizeTV;		// width*height*4
	int BufferSizeDRC;		// width*height*4

	void *TV_Buffer;
	void *DRC_Buffer;

	int Y_Position;

};

#endif