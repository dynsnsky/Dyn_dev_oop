#include <iostream>
#include <string.h>
#include <regex>
using namespace std;

class OCEAN{
	private:
		string input;
		int O, C, E, A, N;
	public:
        OCEAN() : input(""), O(0), C(0), E(0), A(0), N(0) {};
		void Nhap();
		void checkOCEAN();
		bool checkLuuY();
        void Xuat();
};

class ListCheck{
    private: 
        OCEAN** list;
        int n;
    public:
        ListCheck();
        ~ListCheck();
        void Nhap();
        void Xuat();
};

void OCEAN::Nhap() {
    while (true) {
        cout << "(Oxx-Cxx-Exx-Axx-Nxx) ";
        getline(cin, input);

        vector<string> parts;
        string temp = "";
        for (char c : input) {
            if (c == '-') {
                parts.push_back(temp);
                temp = "";
            }
            else temp += c;
        }
        parts.push_back(temp); 

        if (parts.size() != 5 || (parts[0][0] != 'O' || parts[1][0] != 'C' || parts[2][0] != 'E' ||parts[3][0] != 'A' || parts[4][0] != 'N')){
                cout << "Khong hop le, vui long nhap lai!\n";
                continue;
        }
        O = stoi(parts[0].substr(1));
        C = stoi(parts[1].substr(1));
        E = stoi(parts[2].substr(1));
        A = stoi(parts[3].substr(1));
        N = stoi(parts[4].substr(1));

        if (O > 100 || C > 100 || E > 100 || A > 100 || N > 100) {
            cout << "Khong hop le, vui long nhap lai!\n";
            continue;
        }
        break;        
    }
}


void OCEAN::checkOCEAN() {
    cout << O << "\t|Sẵn sàng trải nghiệm (O)\t| " << ((O >= 70) ?
        "Người có điểm cao ở yếu tố này thường là người thích những ý tưởng mới, thích hiểu biết nhiều lĩnh vực nhưng đồng thời cũng thích tự do, không thích bị ràng buộc..."
        : (O <= 30) ?
        "Người có điểm thấp ở yếu tố này thường khá bảo thủ, khó tiếp nhận những ý tưởng mới, lạ. Họ thích sự ổn định, quen thuộc và thực tế."
        : "Không xác định rõ") << "\n";

    cout << C << "\t|Tự chủ tận tâm (C)\t\t| " << ((C >= 70) ?
        "Người có điểm cao ở yếu tố này thường là người chăm chỉ, có khả năng chịu áp lực tốt. Họ thường là người gắn bó, trung thành với tổ chức."
        : (C <= 30) ?
        "Người có điểm thấp ở yếu tố này thường dễ bỏ cuộc, khả năng chịu áp lực, tuân thủ kỷ luật của tổ chức kém."
        : "Không xác định rõ") << "\n";

    cout << E << "\t|Hướng ngoại (E)\t\t| " << ((E >= 70) ?
        "Người có điểm cao ở yếu tố này thường là người nhiệt tình, năng động, giao tiếp tốt, thích thể hiện bản thân."
        : (E <= 30) ?
        "Người có điểm thấp ở yếu tố này thường ngại giao tiếp, không thích sự nổi bật, thích được làm việc độc lập."
        : "Không xác định rõ") << "\n";

    cout << A << "\t|Hòa đồng dễ chịu (A)\t\t| " << ((A >= 70) ?
        "Người có điểm cao ở yếu tố này thường thân thiện, cởi mở, đồng cảm với mọi người nhưng nhiều khi “thiếu chính kiến”."
        : (A <= 30) ?
        "Người có điểm thấp thường đặt lợi ích của bản thân lên trên, ít đồng cảm, chia sẻ với đồng nghiệp, có tính cạnh tranh cao."
        : "Không xác định rõ") << "\n";

    cout << N << "\t|Bất ổn cảm xúc (N)\t\t| " << ((N >= 70) ?
        "Người có điểm cao ở yếu tố này thường có các cảm xúc tiêu cực như: lo lắng, bực bội, tự ti, yếu đuối và khả năng chịu áp lực kém."
        : (N <= 30) ?
        "Người có điểm thấp ở yếu tố này thường kiểm soát được cảm xúc, ứng phó với căng thẳng tốt, ít bị bên ngoài ảnh hưởng đến tâm trạng của bản thân."
        : "Không xác định rõ") << "\n";
}

bool OCEAN::checkLuuY() {
    if (C <= 30 || N >= 70 || E <= 30 && N >= 70)
        return true;
    return false;
}
void OCEAN::Xuat() {
    cout << input << "\n";
}

void ListCheck::Nhap(){
    cin >> n;
    list = new OCEAN * [n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\n\tNguoi thu " << i + 1 << ": ";
        list[i] = new OCEAN();
        list[i]->Nhap();
    }
}

ListCheck::ListCheck() {
    n = 0;
    list = new OCEAN * [n];

}
ListCheck::~ListCheck() {
    for (int i = 0; i < n; i++) {
        delete list[i];
    }
    delete[] list;
}

void ListCheck::Xuat() {
    int countChuY = 0;
    for (int i = 0; i < n; i++) {
        cout << "\n\tNguoi thu " << i + 1 << "\n";
        list[i]->checkOCEAN();
        if (list[i]->checkLuuY()) countChuY++;
    }
    if (countChuY != 0) {
        cout << "\n* Cac truong hop chu y: \n";
        for (int i = 0; i < n; i++) {
            if (list[i]->checkLuuY()) {
                cout << "Nguoi thu " << i+1 << ": ";
                list[i]->Xuat();
            }
        }
    }
}

int main(){
    ListCheck ds;
    cout << "Nhap so nguoi muon kiem tra: ";
    ds.Nhap();
    cout << "\nKET QUA KIEM TRA\n";
    ds.Xuat();
    return 0;
}
