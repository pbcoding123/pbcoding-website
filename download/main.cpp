#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int devcpp(){
    char appDataPath[MAX_PATH];
    if(!GetEnvironmentVariableA("APPDATA", appDataPath, MAX_PATH)){
    	MessageBox(NULL, "Cannot get environment variable \"APPDATA\"", "Initializer", MB_OK|MB_ICONERROR);
        return 1;
    }

    string baseDir=string(appDataPath)+"\\Dev-Cpp";
    string iniPath=baseDir+"\\devcpp.ini";
    string defaultCodePath=baseDir+"\\defaultcode.ini";

    CreateDirectoryA(baseDir.c_str(), NULL);

    cout << "Write main config file <" << iniPath << "> ...\n";
    
    // [Editor]
    WritePrivateProfileStringA("Editor", "EnableAutoSave", "1", iniPath.c_str());
    WritePrivateProfileStringA("Editor", "Interval", "1", iniPath.c_str());
    WritePrivateProfileStringA("Editor", "TrimTrailingSpaces", "1", iniPath.c_str());
    WritePrivateProfileStringA("Editor", "DefaultCode", "1", iniPath.c_str());
    WritePrivateProfileStringA("Editor", "HighColor", "0", iniPath.c_str());

    // [Directories]
    WritePrivateProfileStringA("Directories", "Default", "\"D:\\pbcoding\"", iniPath.c_str());

    // [Editor.Font]
    WritePrivateProfileStringA("Editor.Font", "Name", "\"Consolas\"", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Font", "Size", "15", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Font", "Height", "-20", iniPath.c_str());

    // [Editor.Syntax]    
    WritePrivateProfileStringA("Editor.Syntax", "Assembler", "$00FFAB79, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Character", "$005252D2, clNone, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Comment", "$000CDDC7, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Float", "$0047B37F, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Hexadecimal", "$0047B37F, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Identifier", "$00FFD6BE, clNone, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Illegal Char", "$000000FB, clNone, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Number", "$0047B37F, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Octal", "$0047B37F, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Preprocessor", "$00FFAB79, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Reserved Word", "clTeal, $001E1E1E, 0, 0, 0", iniPath.c_str());     
    WritePrivateProfileStringA("Editor.Syntax", "Space", "$00D8D8D8, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "String", "$0000C6FF, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Symbol", "$0077E5D9, $001E1E1E, 0, 0, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Selected text", "13684944, 0", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Gutter", "13684944, 1973790", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Breakpoints", "16777215, 32896", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Error line", "16777215, 5581567", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Active breakpoints", "16777215, 13421619", iniPath.c_str());
    WritePrivateProfileStringA("Editor.Syntax", "Folding lines", "39423, 5328448", iniPath.c_str());
    
    // defaultcode.ini
    cout << "Write default code file <" << defaultCodePath << "> ...\n";

    ofstream out(defaultCodePath, ios::out | ios::trunc);
    if (!out.is_open()) {
    	MessageBox(NULL, "Cannot open or create <defaultcode.ini> !", "Initializer", MB_OK|MB_ICONERROR);
        return 1;
    }
    
    out << "#include<iostream>\n"
            << "#include<conio.h>\n"
            << "#include<windows.h>\n"
            << "using namespace std;\n\n"
            << "bool pk(int vk){return (GetAsyncKeyState(vk)&0x8000);}\n"
            << "void gotoxy(int x,int y){COORD pos={(short)x,(short)y};HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleCursorPosition(hOut,pos);}\n"
            << "void hidecur(){CONSOLE_CURSOR_INFO cursor_info={1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);}\n"
            << "void putnstr(int n, string s){for(int _=1;_<=n;_++)cout << s;}\n"
            << "void noedit(){HANDLE hStdin=GetStdHandle(STD_INPUT_HANDLE);DWORD mode;GetConsoleMode(hStdin,&mode);mode&=~ENABLE_QUICK_EDIT_MODE;mode&=~ENABLE_INSERT_MODE;mode&=~ENABLE_MOUSE_INPUT;SetConsoleMode(hStdin,mode);}\n"
            << "void setcolor(int x){SetConsoleTextAttribute(GetStdHandle(4294967285u),x);}\n\n"
            << "int main(){\n"
            << "\thidecur();\n"
            << "\tnoedit();\n"
            << "\treturn 0;\n"
            << "}\n";
    
    out.close();
    cout << "Successfully initailize Dev-cpp!\n" << endl;
	return 0;
}

bool SetRegistryString(HKEY hKeyRoot, const wstring& subKey, const wstring& valueName, const wstring& data) {
    HKEY hKey;
    LONG res=RegOpenKeyExW(hKeyRoot, subKey.c_str(), 0, KEY_SET_VALUE, &hKey);
    if(res!=ERROR_SUCCESS){
        return false;
    }
    res = RegSetValueExW(hKey, valueName.c_str(), 0, REG_SZ, (const BYTE*)data.c_str(), (data.length()+1)*sizeof(wchar_t));
    RegCloseKey(hKey);
    return (res==ERROR_SUCCESS);
}

bool setwallpaper(const wstring& image){
	if(!SetRegistryString(HKEY_CURRENT_USER, L"Control Panel\\Desktop", L"WallpaperStyle", L"0")) return false;
    if(!SetRegistryString(HKEY_CURRENT_USER, L"Control Panel\\Desktop", L"TileWallpaper", L"0")) return false;
    if(!SetRegistryString(HKEY_CURRENT_USER, L"Control Panel\\Colors", L"Background", L"74 84 89")) return false;
	if(!SystemParametersInfoW(
        SPI_SETDESKWALLPAPER,
        0,
        (PVOID)image.c_str(),
        SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE
    ))return false;
    return true;
}

void wallpaper(){
	char c;
	cout << "Enter Y to replace the background:";
	cin >> c;
	if(c!='Y') return;
	system("copy playmc.png D:\\tmp114514.png");
    if(!setwallpaper(L"D:\\tmp114514.png")){
    	MessageBox(NULL, "Cannot set desktop wallpaper!", "Initializer", MB_OK|MB_ICONERROR);
	}
	system("del D:\\tmp114514.png");
}

void download(){
	ifstream check(".\\download\\filelist.txt");
	if(check.good()){
		check.close();
		cout << "Already download files!\n";
		return;
	}
	check.close();
	CreateDirectory(".\\download", NULL);
	system("curl -o .\\download\\filelist.txt pbcoding123.dpdns.org/download/filelist.txt -L");
	ifstream flist(".\\download\\filelist.txt");
	string filename;
	flist >> filename;
	while(filename!="#"){
		system(("curl -o .\\download\\"+filename+" pbcoding123.dpdns.org/download/"+filename+" -L").c_str());
		flist >> filename;
	}
	SetCurrentDirectory(".\\download\\");
	flist >> filename;
	while(filename!="#"){
		system(("sm m "+filename).c_str());
		flist >> filename;
	}
}

void software(){
	char c;
	cout << "Enter Y to install softwares:";
	cin >> c;
	if(c!='Y') return;
	system("start .\\download\\7z.exe");
	system("start .\\download\\active.bat");
	system("start .\\download\\cpeditor.exe");
	system("start .\\download\\firefox.exe");
	system("start .\\download\\quicker.msi");
}

int main(){
	CreateDirectory("D:\\pbcoding", NULL);
	devcpp();
	wallpaper();
	download();
	system("copy .\\download\\template.cpp D:\\pbcoding\\template.cpp");
	software();
    system("pause");
	return 0;
}
