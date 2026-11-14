#include<iostream>
#include<conio.h>
#include<windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

bool pk(int vk){return (GetAsyncKeyState(vk)&0x8000);}
void gotoxy(int x,int y){COORD pos={(short)x,(short)y};HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleCursorPosition(hOut,pos);}
void hidecur(){CONSOLE_CURSOR_INFO cursor_info={1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);}
void putnstr(int n, string s){for(int _=1;_<=n;_++)cout << s;}
void noedit(){HANDLE hStdin=GetStdHandle(STD_INPUT_HANDLE);DWORD mode;GetConsoleMode(hStdin,&mode);mode&=~ENABLE_QUICK_EDIT_MODE;mode&=~ENABLE_INSERT_MODE;mode&=~ENABLE_MOUSE_INPUT;SetConsoleMode(hStdin,mode);}
void setcolor(int x){SetConsoleTextAttribute(GetStdHandle(4294967285u),x);}

bool splitExe(const string& inputFile, const string& outputPrefix, size_t chunkSize) {
    ifstream in(inputFile, ios::binary);
    if (!in) {
        cerr << "[ERROR] Cannot open input file: " << inputFile << endl;
        return false;
    }

    vector<char> buffer(chunkSize);
    int fileIndex = 1;

    while (in) {
        in.read(buffer.data(), chunkSize);
        streamsize bytesRead = in.gcount();

        if (bytesRead > 0) {
            ostringstream outName;
            outName << outputPrefix << "_"
                    << setw(3) << setfill('0') << fileIndex
                    << ".chunk";

            ofstream out(outName.str(), ios::binary);
            if (!out) {
                cerr << "[ERROR] Cannot create file!" << outName.str() << endl;
                return false;
            }

            out.write(buffer.data(), bytesRead);
            cout << "[Split] Already have generated: " << outName.str() << " (" << bytesRead << " bytes)\n";
            fileIndex++;
        }
    }
    cout << ">>> Successfully split! Generate totally " << (fileIndex - 1) << " chunk(s).\n" << endl;
    return true;
}
bool mergeExe(const string& inputPrefix, const string& outputFile) {
    ofstream out(outputFile, ios::binary);
    if (!out) {
        cerr << "[ERROR] Cannot create output file: " << outputFile << endl;
        return false;
    }
    vector<char> buffer(1024 * 1024);
    int fileIndex = 1;
    while (true) {
        ostringstream inName;
        inName << inputPrefix << "_"
               << setw(3) << setfill('0') << fileIndex
               << ".chunk";

        ifstream in(inName.str(), ios::binary);
        if (!in) {
            break;
        }
        while (in) {
            in.read(buffer.data(), buffer.size());
            streamsize bytesRead = in.gcount();
            if (bytesRead > 0) {
                out.write(buffer.data(), bytesRead);
            }
        }
        cout << "[Merge] Already have written into: " << inName.str() << "\n";
        fileIndex++;
    }
    out.close();
    cout << ">>> Successfully merge into: " << outputFile << "\n" << endl;
    return true;
}
string OpenDialog() {
    char savePath[MAX_PATH]="D:\\";
    OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrInitialDir = savePath;
    ofn.lpstrTitle = "Open file...";
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

    if (GetOpenFileName(&ofn) == TRUE) {
        return string(szFileName);
    }
    return "";
}

int main(int argc, char* argv[]){
	hidecur();
	noedit();
	if(argc>=2){
		if(argv[1][0]=='s'){
			string t=argv[2];
			string pre=t.substr(t.find_last_of('\\')+1);
			pre = pre.substr(0, pre.find_last_of('.'));
			splitExe(t, pre, 10485760);
		}
		else if(argv[1][0]=='m'){
			string t=argv[2];
			string pre=t.substr(t.find_last_of('\\')+1);
			pre = pre.substr(0, pre.find_last_of('.'));
			pre = pre.substr(0, pre.find_last_of('_'));
			mergeExe(pre, pre+".exe");
		}
		return 0;
	}
	char c;
	cout << "Split(s) or Merge(m):";
	cin >> c;
	if(c=='s'){
		string t=OpenDialog();
		string pre=t.substr(t.find_last_of('\\')+1);
		pre = pre.substr(0, pre.find_last_of('.'));
		splitExe(t, pre, 10485760);
	}
	else{
		string t=OpenDialog();
		string pre=t.substr(t.find_last_of('\\')+1);
		pre = pre.substr(0, pre.find_last_of('.'));
		pre = pre.substr(0, pre.find_last_of('_'));
		mergeExe(pre, pre+".exe");
	}
	return 0;
}

