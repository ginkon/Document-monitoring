#include "FileSystemWatcher.h"
#include <stdio.h>
#include <locale.h>
#include <assert.h>
#include <tchar.h>
#include <conio.h>
void __stdcall MyDeal(FileSystemWatcher::ACTION act, LPCWSTR filename, LPVOID lParam)
{
	static FileSystemWatcher::ACTION pre = FileSystemWatcher::ACTION_ERRSTOP;
	switch (act)
	{
	case FileSystemWatcher::ACTION_ADDED:
		wprintf_s(L"Added     - %s\n", filename);
		break;
	case FileSystemWatcher::ACTION_REMOVED:
		wprintf_s(L"Removed   - %s\n", filename);
		break;
	case FileSystemWatcher::ACTION_MODIFIED:
		wprintf_s(L"Modified  - %s\n", filename);
		break;
	case FileSystemWatcher::ACTION_RENAMED_OLD:
		wprintf_s(L"Rename(O) - %s\n", filename);
		break;
	case FileSystemWatcher::ACTION_RENAMED_NEW:
		assert(pre == FileSystemWatcher::ACTION_RENAMED_OLD);
		wprintf_s(L"Rename(N) - %s\n", filename);
		break;
	case FileSystemWatcher::ACTION_ERRSTOP:
	default:
		wprintf_s(L"---ERROR---%s\n", filename);
		break;
	}
	pre = act;
}
int main()
{
	LPCTSTR sDir = TEXT("D:\\监测文件夹");
	DWORD dwNotifyFilter = FileSystemWatcher::FILTER_FILE_NAME | FileSystemWatcher::FILTER_DIR_NAME;
	FileSystemWatcher fsw;
	bool r = fsw.Run(sDir, true, dwNotifyFilter, &MyDeal, 0);
	if (!r) return -1;
	_tsetlocale(LC_CTYPE, TEXT("chs"));
	_tprintf_s(TEXT("Watch%s\n"), sDir);
	_tprintf_s(TEXT("按 <q> 退出.\n"));
	while (_getch() != 'q');
	fsw.Close(1000);
	return 0;
}
