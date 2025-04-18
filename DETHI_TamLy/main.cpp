#include <iostream>
#include <string>
#include <vector>
using namespace std;

class YeuTo{
    protected:
        int score;
    public:
        YeuTo(int s = 0) : score(s) {}
        int getScore() const {return score;}
        virtual string DacDiem() = 0;
        virtual string ChiSoCao() = 0;
        virtual string ChiSoThap() = 0;
        void Xuat(){
            cout << score << "\t|"<<DacDiem()<<"\t | " <<((score >= 70) ? ChiSoCao(): (score <= 30) ? ChiSoThap(): "Không xác định rõ") << "\n";
        }
        ~YeuTo() {}
};

class O: public YeuTo {
    public:
        using YeuTo::YeuTo;
        string DacDiem() override {
            return "Sẵn sàng trải nghiệm (O)";
        }
        string ChiSoThap() override {
            return "Người có điểm cao ở yếu tố này thường là người thích những ý tưởng mới, thích hiểu biết nhiều lĩnh vực nhưng đồng thời cũng thích tự do, không thích bị ràng buộc...";
        }
        string ChiSoCao() override {
            return "Người có điểm thấp ở yếu tố này thường khá bảo thủ, khó tiếp nhận những ý tưởng mới, lạ. Họ thích sự ổn định, quen thuộc và thực tế.";
        }
};

class C: public YeuTo {
public:
        using YeuTo::YeuTo;
        string DacDiem() override {
            return "Tự chủ tận tâm (C)";
        }
        string ChiSoThap() override {
            return "Người có điểm cao ở yếu tố này thường là người chăm chỉ, có khả năng chịu áp lực tốt. Họ thường là người gắn bó, trung thành với tổ chức.";
        }
        string ChiSoCao() override {
            return  "Người có điểm thấp ở yếu tố này thường dễ bỏ cuộc, khả năng chịu áp lực, tuân thủ kỷ luật của tổ chức kém.";
        }
};

class E: public YeuTo {
public:
        using YeuTo::YeuTo;
        string DacDiem() override {
            return "Hướng ngoại (E)";
        }
        string ChiSoThap() override {
            return  "Người có điểm cao ở yếu tố này thường là người nhiệt tình, năng động, giao tiếp tốt, thích thể hiện bản thân.";
        }
        string ChiSoCao() override {
            return   "Người có điểm thấp ở yếu tố này thường ngại giao tiếp, không thích sự nổi bật, thích được làm việc độc lập.";

        }
};

class A: public YeuTo {
public:
        using YeuTo::YeuTo;
        string DacDiem() override {
            return "Hòa đồng dễ chịu (A)";
        }
        string ChiSoThap() override {
            return  "Người có điểm cao ở yếu tố này thường thân thiện, cởi mở, đồng cảm với mọi người nhưng nhiều khi “thiếu chính kiến”.";
        }
        string ChiSoCao() override {
            return  "Người có điểm thấp thường đặt lợi ích của bản thân lên trên, ít đồng cảm, chia sẻ với đồng nghiệp, có tính cạnh tranh cao.";
        }
};

class N: public YeuTo {
public:
        using YeuTo::YeuTo;
        string DacDiem() override {
            return "Bất ổn cảm xúc (N)";
        }
        string ChiSoThap() override {
            return  "Người có điểm cao ở yếu tố này thường có các cảm xúc tiêu cực như: lo lắng, bực bội, tự ti, yếu đuối và khả năng chịu áp lực kém.";
        }
        string ChiSoCao() override {
            return  "Người có điểm thấp ở yếu tố này thường kiểm soát được cảm xúc, ứng phó với căng thẳng tốt, ít bị bên ngoài ảnh hưởng đến tâm trạng của bản thân.";
        }
};

class NGUOI {
    private:
        string input;
        O scoreO;
        C scoreC;
        E scoreE;
        A scoreA;
        N scoreN;
    public:
        NGUOI() : input(""), scoreO(0), scoreC(0), scoreE(0), scoreA(0), scoreN(0) {}
        ~NGUOI(){}
        void Nhap();
        bool KT(vector <string> &, string&);
        bool checkLuuY();
        int getScoreC() const { return scoreC.getScore(); }
        int getScoreE() const { return scoreE.getScore(); }
        int getScoreN() const { return scoreN.getScore(); }
        void Xuat();
};

class ListCheck {
    private:
        NGUOI** list;
        int n;
    public:
        ListCheck();
        ~ListCheck();
        void Nhap();
        void XuatKQ();
        void XuatLuuY();
        void Xuat1nguoi(int);
};

bool NGUOI::KT(vector <string> &parts, string &temp){
    for (char c : input) {
        if (c == '-') {
            parts.push_back(temp);
            temp = "";
        }
        else temp += c;
    }
    parts.push_back(temp);

    if (parts.size() != 5 ||
        parts[0][0] != 'O' || parts[1][0] != 'C' ||
        parts[2][0] != 'E' || parts[3][0] != 'A' || parts[4][0] != 'N') {
        cout << "Khong hop le, vui long nhap lai!\n";
        return false;
    }
    return true;
}

void NGUOI::Nhap() {
    while (true) {
        cout << "(Ox-Cx-Ex-Ax-Nx) ";
        getline(cin, input);
        vector<string> parts;
        string temp = "";
        if (!KT(parts, temp)) continue;
        else {
            int o = stoi(parts[0].substr(1));
            int c = stoi(parts[1].substr(1));
            int e = stoi(parts[2].substr(1));
            int a = stoi(parts[3].substr(1));
            int n = stoi(parts[4].substr(1));

            if (o > 100 || c > 100 || e > 100 || a > 100 || n > 100 || o < 0 || c < 0 || e < 0 || a < 0 || n < 0) {
                cout << "Khong hop le, vui long nhap lai!\n";
                continue;
            }
            scoreO = O(o);
            scoreC = C(c);
            scoreE = E(e);
            scoreA = A(a);
            scoreN = N(n);
            break;
        }
    }
}

bool NGUOI::checkLuuY() {
    int c = scoreC.getScore();
    int e = scoreE.getScore();
    int n = scoreN.getScore();
    return (c <= 30 || n>=70 || (e <= 30 && n >= 70));
}

void NGUOI::Xuat() {
    cout << input << "\n";
    scoreO.Xuat();
    scoreC.Xuat();
    scoreE.Xuat();
    scoreA.Xuat();
    scoreN.Xuat();
}

ListCheck::ListCheck() {
    n = 0;
    list = new NGUOI * [n];
}

ListCheck::~ListCheck() {
    for (int i = 0; i < n; i++)
        delete list[i];
    delete[] list;
}

void ListCheck::Nhap(){
    cout << "Nhap so nguoi muon kiem tra: ";
    cin >> n;
    cin.ignore();
    list = new NGUOI* [n];
    for (int i = 0; i < n; i++) {
        cout << "\n\tNguoi thu " << i + 1 << ": ";
        list[i] = new NGUOI();
        list[i]->Nhap();
    }
}

void ListCheck::XuatKQ() {
    for (int i = 0; i < n; i++) {
        cout << "\n\tNguoi thu " << i + 1 << "\n";
        list[i]->Xuat();
    }
}
void ListCheck::XuatLuuY(){
    int countChuY = 0;
    for (int i = 0; i < n; i++)
        if (list[i]->checkLuuY()) countChuY++;
    if (countChuY > 0) {
        cout << "\n* CAC TRUONG HOP CAN LUU Y:\n";
        for (int i = 0; i < n; i++) {
            if (list[i]->checkLuuY()) {
                cout << "Nguoi thu " << i + 1 << ": ";
                int c = list[i]->getScoreC();
                int e = list[i]->getScoreE();
                int n = list[i]->getScoreN();
                if (c <= 30)
                    cout << "Người có chỉ số C thấp có những biểu hiện vô tổ chức, bỏ việc giữa chừng, thiếu trách nhiệm, bất cẩn, cẩu thả và bốc đồng trong công việc.";
                else  if (e <= 30)
                    cout << "Đặc biệt người có chỉ số E thấp và N cao ảnh hưởng đến việc tìm kiếm và kết nối với thông tin, hệ quả sẽ khiến một cá nhân có xu hướng tránh tiếp cận với nguồn thông tin mới, trở nên thiếu hụt kỹ năng và hạn chế việc tiếp cận các thông tin nghề nghiệp quan trọng.";
                else cout << "Người có chỉ số N cao sẽ có các cảm xúc tiêu cực, cảm giác căng thẳng trở nên lớn hơn và giảm đi sự chắc chắn trong việc cam kết lâu dài với một công việc.";
            }
        }
    }
    else cout << "\nKhong co truong hop nao can luu y.\n";
}

void ListCheck::Xuat1nguoi(int index) {
        list[index-1]->Xuat();
}

int main(){
    NGUOI person;
    person.Nhap();
    person.Xuat();
    ListCheck ds;
    ds.Nhap();
    cout << "\nChon 1 nguoi trong danh sach: ";
    int index;
    cin >> index;
    cout << "\nKET QUA KIEM TRA\n";
    ds.XuatKQ();
    ds.Xuat1nguoi(index);
    ds.XuatLuuY();
    return 0;
}