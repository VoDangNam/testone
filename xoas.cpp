#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>


using namespace std;
//HÀM  
bool test_number(string number)
    {
        for(int i=0;i<number.length();i++)
        {
            if(number[i]<48||number[i]>57||number[i]==' ')
            {
                return false;
            }
        }
        return true;
    }
bool Kiem_tra_ngay (int d, int m, int y)
    {
        if (y<0)
        {
            return false;
        }
        else
        {
            if (m<1 || m>12)
            {
                return false;
            }
            else
            {
                if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 ||m==12)
                {
                    if (d<1 || d>31)
                    {
                        return false;
                    }
                }
                else if (m==4 || m==6 || m==9 || m==11)
                {
                    if (d<1 || d>30)
                    {
                        return false;
                    }
                }
                else if (m==2)
                {
                    if(y%4==0 && (y%400==0 || y%100!=0))
                    {
                        if (d<1 || d>29)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (d<1 || d>28)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
bool kiemTraKyTu (string s)
{
    //kiem tra xem trong chuoi co chua ky tu so hay khong
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z')) //neu khong thuoc cac ky tu chu thi tra ve false
        {
            return false;
        }
    }
    return true;
}
string format(string name)
{
    //chinh lai phong chu cho phu hop cac chu cai dau viet hoa va giua cac chu chi co 1 dau cach
    int n=name.length();
    //Xoa dau cach
    for(int i=0; i<n; i++)
    {
        if(name[0]==' ')
        {
            for (int k=0; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
        if(name[i]==' '&&name[i+1]==' ')
        {
            for (int k=i; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
    }
    name[n] = '\0';
    //Viet hoa cac chu cai dau
    for (int i=0; i<n; i++)
    {
        if(name[0]>='a'&&name[0]<='z')
        {
            name[0]-=32;
        }
        if (name[i-1]==' ' && name[i]>='a' && name[i]<='z')
        {
            name[i]-=32;
        }
        if (name[i-1]!=' ' && name[i]>='A' && name[i]<='Z')
        {
            name[i]+=32;
        }
    }
    return name;
}

bool kiemTraMa(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z') &&(s[i] <'0' || s[i] > '9') )
        {
            return false;
        }
    }
    return true;
}


//CLASSS
class Date{
	int d,m,y;
	public:
		void nhap();
		void xuat();
		
};

class Quan_ly_quan_cafe{
	protected:
		Date Ngay_nhap;
		string Ten_nguoi_nhap;
	public:
		void nhap();
		void xuat();
	
};

void Date::nhap(){
	do{
		 do {
          cout<<"\n\tNhap vao ngay : ";
	      cin>>d;
            if (cin.fail() || d <= 0) {
                cout << "\n\tNgay khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
          } while (cin.fail() || d <= 0);
	      
	       do {
              cout<<"\n\tNhap vao thang : ";
	         cin>>m;
            if (cin.fail() || m <= 0) {
                cout << "\n\tThang khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            } while (cin.fail() || m <= 0);
	      
	      
	       do {
               cout<<"\n\tNhap vao nam : ";
	      cin>>y;
            if (cin.fail() || y <= 0) {
                cout << "\n\tThang khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            } while (cin.fail() || y <= 0);
	     	
	      if(Kiem_tra_ngay(this->d,this->m,this->y)==false)
	      {
	      	cout<<"\n\tXin loi ! Ngay thang nam cua ban khong hop le !!";
	      	cout<<"\nVui long nhap lai ";
	      	cin.clear();
            cin.ignore(10000, '\n');
		  }
	}while(Kiem_tra_ngay(this->d,this->m,this->y)==false);
	

}

void Date::xuat(){
	cout<<d<<"/"<<m<<"/"<<y<<endl;
}
void Quan_ly_quan_cafe::nhap(){
	cout<<"\n\t\tNHAP\t\t\n";
	Ngay_nhap.nhap();
	 do{
	          	cout<<"\n\tNhap vao ten nguoi nhap : ";
	                fflush(stdin);
	                getline(cin,Ten_nguoi_nhap);
		        if(kiemTraKyTu (Ten_nguoi_nhap) == false)
		        {
		        	cout<<"\n\tTen nguoi nhap da chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				}
				
			}while (kiemTraKyTu (Ten_nguoi_nhap)==false) ;

} 
void Quan_ly_quan_cafe::xuat(){
	cout<<"\n\t\tXUAT\t\t\n";
	cout<<"\n\tDa duoc "<<format(Ten_nguoi_nhap)<<endl;
	cout.width(25-Ten_nguoi_nhap.length());
	cout<<" Nhap vao ngay : ";
	Ngay_nhap.xuat();
}
class Quan_ly_nhan_vien : public Quan_ly_quan_cafe{
	private:
		string Ten_nhan_vien;
		string Chuc_vu;
		string Msnv;
		int So_gio_lam;
	
	public:
		void nhap()
		{
			Quan_ly_quan_cafe::nhap();
			
			 do{
			 cout<<"\n\tNhap vao ten nhan vien : ";
			  fflush(stdin);
			   getline(cin,Ten_nhan_vien);
		      if(kiemTraKyTu(Ten_nhan_vien) == false)
		        {
		        	cout<<"\n\tTen nhan vien da chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				}
				
			}while (kiemTraKyTu (Ten_nhan_vien)==false) ;
			
			do{
			 cout<<"\n\tNhap vao chuc vu cua ban di "<< Chuc_vu<<" : ";
			fflush(stdin);
			getline(cin,Chuc_vu);
		
			
	          	
		        if(kiemTraKyTu (Chuc_vu) == false)
		        {
		        	cout<<"\n\tChuc vu da chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				}
				
			}while (kiemTraKyTu (Chuc_vu)==false) ;
			
			do{
				cout<<"\n\tNhap vao ma so nhan vien : ";
			   fflush(stdin);
			   getline(cin,Msnv);	
			}while(kiemTraMa(Msnv)==false);
			
			do {
            
			cout<<"\n\tNhap vao so gio lam cua ban trong hom nay : ";
			cin>>So_gio_lam;
            if (cin.fail() || So_gio_lam <= 0) {
                cout << "\n\tSo luong khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || So_gio_lam <= 0);
			
			
		}
		void xuat(){
			Quan_ly_quan_cafe::xuat();
		
        	cout<<"\n\tTen nhan vien : "<<Ten_nhan_vien;
        
		
			cout<<"\n\tTen nhan vien : "<<format(Ten_nhan_vien);
			cout<<"\n\tChuc vu : "<<Chuc_vu;
			cout<<"\n\tMa so nhan vien : "<<Msnv;
			cout<<"\n\tTien luong cua "<<Ten_nhan_vien<<" la : "<<Tinh_tien_luong();
			
		}
	float Tinh_tien_luong(){
		return So_gio_lam *20000;
		}
		
};

class Quan_ly_nguyen_lieu : public Quan_ly_quan_cafe {
private:
    string Ten_nguyen_lieu;
    float So_luong;
    float Gia;
    Date Thoi_gian_nhap;

public:
    void nhap() {
        Quan_ly_quan_cafe::nhap();
        do{
				
	          	cout<<"\n\tNhap vao ten nguyen lieu :";
		          fflush(stdin);
		        getline(cin,Ten_nguyen_lieu);
		        if(kiemTraKyTu (Ten_nguyen_lieu) == false)
		        {
		        	cout<<"\n\tTen nguyen lieu da chua ki tu khong hop le !!!";
		        	cout<<"\n\tVui long nhap lai ";
				}
				
			}while (kiemTraKyTu (Ten_nguyen_lieu)==false) ;

        do {
            cout << "\n\tNhap vao so luong : ";
            cin >> So_luong;
            if (cin.fail() || So_luong <= 0) {
                cout << "\n\tSo luong khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || So_luong <= 0);
          
          do {
            
			cout << "\n\tNhap vao gia : ";
               cin >> Gia;

            if (cin.fail() || Gia <= 0) {
                cout << "\n\tGia tien khong hop le! Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || Gia <= 0);
        
        cout << "\n\tNhap vao Thoi gian nhap  ";
        Thoi_gian_nhap.nhap();
    }

    void xuat() {
        Quan_ly_quan_cafe::xuat();
       
       	cout << "\n\tTen nguyen lieu : " << format(Ten_nguyen_lieu);
        cout.width(25-Ten_nguyen_lieu.length());
        cout << "\n\tSo luong : " << So_luong;
        cout << "\n\tThoi gian nhap : ";
        Thoi_gian_nhap.xuat();
        cout << "\n\tTong tien phai tra : " << Tinh_tien();
    }

    float Tinh_tien() {
        return So_luong * Gia;
    }

};

class Quan_ly_don_hang:public Quan_ly_quan_cafe{
	private:
	//	string Ten_mon;
		int Gia=0;
		int So_luong=0;
		int Tong_tien;
		string Hinh_thuc_tra;
	public:
		void nhap()
		{
			Quan_ly_quan_cafe::nhap();
			cout<<"\n\t1.Cafe Den  |10.000 vdn | ";
			cout<<"\n\t2.Cafe Viet |15.000 vnd | ";
			cout<<"\n\t3.Bo huc    |20.000 vnd | ";
			cout<<"\n\t0.Tro lai                 ";
			int luachon;
		
			while(true)
			{
				cout<<"\n\tNhap vao lua chon cua quy khach : ";
				cin>>luachon;
				if(luachon==1)
				{
					cout<<"\n\tLua chon cua ban la Cafe Den ";
					cout<<"\n\tNhap vao so luong :";
					cin>>So_luong;
					Gia+=So_luong*10000;
				}
				else if(luachon==2)
				{
					cout<<"\n\tLuachon cua ban la Cafe Viet ";
						cout<<"\n\tNhap vao so luong :";
					cin>>So_luong;
					Gia+=So_luong*15000;
				}
				else if (luachon==3){
					cout<<"\n\tLua chon cua ban la Bo huc ";
					cout<<"\n\tNhap vao so luong :";
					cin>>So_luong;
						Gia+=So_luong*20000;
				}
				else{
				break;
		     	}
		    Tong_tien=Gia;
			cout<<"tong tien :"<<Tong_tien<<" vnd\n";
			
			}
			
			cout << "\n\tNhap vao hinh thuc tra (Tien mat(A), VnPay(B), ATM(C)): ";
               	cin.ignore();
	            getline(cin, Hinh_thuc_tra);
	            
				do{
			    
		
		        if(kiemTraKyTu (Hinh_thuc_tra) == false)
		        {
		        	cout<<"\n\tBan da nhap chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				    cout << "\n\tNhap vao hinh thuc tra (Tien mat(A), VnPay(B), ATM(C)): ";
               	      cin.ignore();
	              getline(cin, Hinh_thuc_tra);
				}
				
			}while (kiemTraKyTu (Hinh_thuc_tra)==false) ;
			
		}
		
};
int main()
{
    Quan_ly_don_hang a;
    a.nhap();
	
	return 0;
}