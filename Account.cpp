#include<iostream>
#include<fstream>
#include<string.h>
#include<graphics.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
int choice;
char logged_in[30];
int LIGHTBROWN;
char file[30];
char buf[30];
int window_x=1293,window_y=696;

time_t t = time(NULL);
tm* timeinfo = localtime(&t);

class Account{
	protected:
	char name[20],gmail[30],password[6],address[20];
	public:
		
//		char* get_name(){
//			return name;
//		}
		
		int create(){
				
			readimagefile("images\\login_page\\register1.jpg",442.5,81.5,442.5+475,81.5+600);
			int fx1=479,fy1=208;
			LIGHTBROWN = COLOR(200, 140, 103);
			setbkcolor(LIGHTBROWN);
			settextstyle(4,0,3);
			setcolor(WHITE);
			int i=0;
			
			while(1){
				if(kbhit()){
					name[i]=getch();
					if(name[i]==27){
						return 210;
					}
					if(name[i]!=13 && i<=19){
						if(name[i]==8 && i>0){
							i--;  
							name[i]='\0';
						}
						else if (name[i] != 8) {
							i++;
							name[i]='\0';
						}
						readimagefile("images\\login_page\\fill_up.jpg",fx1+18,fy1+15,fx1+385,fy1+54);
						outtextxy(fx1+18,fy1+20, name);
					}
					else{
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()> 489 &&  mousey()> 576 &&mousex()< 641 &&  mousey()< 643){
						return 210;
					}
				}
			}
			name[i]='\0';
			
//____________________________________DOUBBLE NAME CHECK ________________________________________________________________________
			
			Account a2;
			ifstream fin("data.dat");
			fin.seekg(0,ios::beg);
			fin.read((char*)&a2,sizeof(a2));
			while(fin){
				cout<<a2.name<<endl;
				if(strcmp(a2.name,name)==0){
					outtextxy(300,100,"NAME ALREADY EXITS !!");
					getch();
//					cout<<"name already exists !!";
					return 210;
				}
				fin.read((char*)&a2,sizeof(a2));
			}
			
			i=0,fx1=479,fy1=293;
			
			while(1){
				if(kbhit()){
					address[i]=getch();
					if(address[i]==27){
						return 220;
					}
					if(address[i]!=13 && i<=19){
						if(address[i]==8 && i>0){
							i--;  
							address[i]='\0';
						}
						else if (address[i] != 8) {
							i++;
							address[i]='\0';
						}
						readimagefile("images\\login_page\\fill_up.jpg",fx1+18,fy1+15,fx1+385,fy1+54);
						outtextxy(fx1+18,fy1+20, address);
					}
					else{
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()> 489 &&  mousey()> 576 &&mousex()< 641 &&  mousey()< 643){
						return 210;
					}
				}
			}
			address[i]='\0';
			
//			while((address[i]=getch())!=13 && i<=19){ 
//				if(address[i]==8 && i>0){
//					i--;  
//					address[i]='\0';
//				}
//				else{
//					i++;
//					address[i]='\0';
//				}
//				readimagefile("images\\login_page\\fill_up.jpg",fx1,fy1,fx1+404,fy1+57);
//				outtextxy(fx1+15,fy1+20, address);
//			}
//			for(int j=i;j<20;j++){
//				address[j]='\0';
//			}
//			cout<<address<<endl;
			
			i=0,fx1=482,fy1=382;
			while((gmail[i]=getch())!=13 && i<=19){ 
				if(gmail[i]==8 && i>0){
					i--;  
					gmail[i]='\0';
				}
				else{
					i++;
					gmail[i]='\0';
				}
				readimagefile("images\\login_page\\fill_up.jpg",fx1+18,fy1+15,fx1+385,fy1+54);
				outtextxy(fx1+18,fy1+20, gmail);
			}
			for(int j=i;j<20;j++){
				gmail[j]='\0';
			}
			cout<<gmail<<endl;
			
				//for password---
			i=0,fx1=482,fy1=469;
			char z[10]={0};
			while(1){
				if(kbhit()){
					password[i]=getch();
					if(password[i]==27){
						return 220;
					}
					if(password[i]!=13 && i<=4){
						if(password[i]==8 && i>0){
							i--;
							password[i]='\0';
							z[i]='\0';
						}
						else if (password[i] != 8) {
							z[i]='*';
							i++;
							password[i]='\0';
							z[i]='\0';
						}
						readimagefile("images\\login_page\\fill_up.jpg",fx1+18,fy1+15,fx1+385,fy1+54);
						outtextxy(fx1+18,fy1+20, z);
					}
					else{
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()> 679 &&  mousey()> 573 &&mousex()< 885 &&  mousey()< 641 ){
						break;
					}
					else if(mousex()> 489 &&  mousey()> 576 &&mousex()< 641 &&  mousey()< 643){
						return 210;
					}
				}
			}
			password[i]='\0';
			
//			while((password[i]=getch())!=13 && i<=5){  //name[0] = rush
//				if(password[i] == 8 && i>0){
//					i--;
//					password[i]='\0';
//					z[i]='\0';
//				}
//				else{
//					z[i]='*';
//					i++;
//					password[i]='\0';
//					z[i]='\0';
//				}
//				readimagefile("images\\login_page\\fill_up.jpg",fx1,fy1,fx1+404,fy1+57);
//				outtextxy(fx1+15,fy1+20, z);
//			}
//			for(int j=i;j<6;j++){
//				password[j]='\0';
//			}
			cout<<"password : "<<password<<endl;
			char new_ac_file[30];
			strcpy(new_ac_file,"users\\");
			strcat(new_ac_file,name);
			strcat(new_ac_file,".dat");
			ofstream fout(new_ac_file,ios::out | ios::binary);
		}
		
		int login(){
			LIGHTBROWN = COLOR(200, 140, 103);
			setbkcolor(LIGHTBROWN);
			settextstyle(4,0,3);
			setcolor(WHITE);
			readimagefile("images\\login_page\\login1.jpg",442, 161, 442+475, 161+440);
			int fx1=479,fy1=288;
//			setbkcolor(LIGHTBROWN);
//			settextstyle(4,0,3);
			int i=0;
			name[20] = {0};
			
			while(1){
				if(kbhit()){
					name[i]=getch();
					if(name[i]==27){
						return 220;
					}
					if(name[i]!=13 && i<=19){
						if(name[i]==8 && i>0){
							i--;  
							name[i]='\0';
						}
						else if (name[i] != 8) {
							i++;
							name[i]='\0';
						}
						
						readimagefile("images\\login_page\\fill_up.jpg",fx1+15,fy1-2,fx1+375,fy1+54);
						outtextxy(fx1+15,fy1+20, name);
					}
					else{
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()> 482 &&  mousey()> 484 &&mousex()< 648 &&  mousey()< 554 ){
						return 220;
					}
				}
			}
			name[i]='\0';
			cout<<"name : "<<name<<endl;
			cout<<strlen(name);
			
			strcpy(logged_in,name);
//____________________________________ NAME CHECK _______________________________________________________________________________________
			Account a2;
			ifstream fin("data.dat");
			fin.seekg(0,ios::beg);
			fin.read((char*)&a2,sizeof(a2));
			while(fin){
				cout<<"name : "<<name<<endl;
				if(strcmp(a2.name,name)==0){
					
//____________________________________ password CHECK _______________________________________________________________________________________					
				i=0,fx1=480,fy1=374;
				char z[10];
				while(1){
				if(kbhit()){
					password[i]=getch();
					if(password[i]!=13 && i<=4){
						if(password[i]==8 && i>0){
							i--;
							password[i]='\0';
							z[i]='\0';
						}
						else if (password[i] != 8) {
							z[i]='*';
							i++;
							password[i]='\0';
							z[i]='\0';
						}
						readimagefile("images\\login_page\\fill_up.jpg",fx1+10,fy1+10,fx1+400-10,fy1+56-10);
						outtextxy(fx1+15,fy1+20, z);
					}
					else{
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()> 657 &&  mousey()> 485 &&mousex()< 881 &&  mousey()< 554 ){
						break;
					}
					else if(mousex()> 657 &&  mousey()> 485 &&mousex()< 881 &&  mousey()< 554){
						return 220;
					}
				}
			}
			password[i]='\0';
		
			
					if(strcmp(a2.password,password)==0){
						if(strcmp(name,"admin")==0){
							return 2213;
						}
						else{
							return 2211;
						}
					}
					else{
						cout<<"incorrect password!!!\n";
						return 220;
					}
				}
				fin.read((char*)&a2,sizeof(a2));
			}
			cout<<"Name not found !!\n";
		}
};

class Store{
	protected:
	char item_name[20];
	int quantity;
	char item_code[5];
	double price;
	const int logged;
	public:
		Store(int value=0) : logged(value) {}
		
		void check_log(){
			cout<<logged<<endl;
		}
		
int startup_page(){
			
			int bx1=498,by1=285;
			setcolor(1);
			while(1){
			
				readimagefile("images\\login_page\\startup_page.jpg",0,0,1293,696);
//				readimagefile("images\\login_page\\create_button.jpg",bx1,by1,bx1+295,by1+77);
//				readimagefile("images\\login_page\\login_button.jpg",bx1,by1+102,bx1+295,by1+77+102);
//				readimagefile("images\\login_page\\exit_button.jpg",bx1,by1+204,bx1+295,by1+77+204);
				
				if(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1 && mousey()<=by1+77){
					rectangle(bx1-3,by1-3,bx1+298,by1+77+3);
					while(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1 && mousey()<=by1+77){
						if(GetAsyncKeyState(VK_LBUTTON)){
								setcolor(1);
	           					return 11;
	      				  }
					}
				}
				else if(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1+102 && mousey()<=by1+77+102){
					rectangle(bx1-3,by1+102-3,bx1+295+3,by1+77+102+3);
					while(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1+102 && mousey()<=by1+77+102){
						if(GetAsyncKeyState(VK_LBUTTON)){
							setcolor(1);
							return 12;
	      				  }
					}
				}
				else if(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1+204 && mousey()<=by1+77+204){
					rectangle(bx1-3,by1+204-3,bx1+298,by1+77+204+3);
					while(mousex()>=bx1 && mousex()<=bx1+295 && mousey()>=by1+204 && mousey()<=by1+77+204){
						if(GetAsyncKeyState(VK_LBUTTON)){	
							setcolor(1);
							return 444;
	      				  }
					}
				}
				else{
					if(GetAsyncKeyState(VK_LBUTTON)){
	      			}
					delay(100);
				}
			}
		}
		
 		int display(){
			delay(100);
			price=0;
			Store a2[30];
			int px1=50,py1=113;
			char loc[40][100];
			LIGHTBROWN = COLOR(255, 185, 136);
			setbkcolor(LIGHTBROWN);
			setcolor(WHITE);
			settextstyle(3,0,1);
			readimagefile("images\\homepage\\guest_homepg.jpg",0,0,window_x,window_y);
			ifstream fin("data\\items.dat");
			fin.seekg(0,ios::beg);
			int i=0;
			fin.read((char*)&a2[i],sizeof(a2[i]));
			while(fin){
				strcpy(loc[i],"images\\clothes\\");
				strcat(loc[i],a2[i].item_code);
				strcat(loc[i],".jpg");
				i++;
				fin.read((char*)&a2[i],sizeof(a2[i]));
			}
			
			cout<<logged<<endl;
			
			int max = i-1;
			
			for(int j=0;j<6;j++){
				readimagefile(loc[j],px1,py1,px1+147,py1+147);
				outtextxy(px1+164+10,py1+3,a2[j].item_name);
				char buf[50];
				sprintf(buf,"%.2f",a2[j].price);
				outtextxy(px1+164+10,py1+3+45, buf);
					outtextxy(px1+164+10,py1+3+84,"description ");
				sprintf(buf,"%d",a2[j].quantity);
				outtextxy(px1+165+10,py1+3+168,buf);
				
				px1+=419;
				if(px1+419>1360){
					px1=50;
					py1+=124+147;
				}
				
			}
			cout<<max;
			
			int nx1=1168, ny1=651, bx1=1045, by1=651, ex1=100, ey1=639+11;
			int start=0,end=6;
				readimagefile("images\\homepage\\footer.jpg",0,639,window_x,window_y);
				int last;
				if(max>5){
					last=false;
				}
				
			while(1){
//				readimagefile("images\\homepage\\footer.jpg",0,639,window_x,window_y);
				if(mousex() > nx1 && mousex() < nx1 + 109 && mousey() > ny1 && mousey() < ny1 + 33 ){
					readimagefile("images\\homepage\\next_button.jpg",nx1, ny1, nx1 + 109, ny1 + 33);
					while(mousex() > nx1 && mousex() < nx1 + 109 && mousey() > ny1 && mousey() < ny1 + 33 ){
					if(GetAsyncKeyState(VK_LBUTTON)){
						if(!last){
							start+=6;
							
							i=start;
							readimagefile("images\\homepage\\guest_homepg.jpg",0,0,window_x,window_y);
							
								px1=50,py1=113;
								end=start+6;
								if(end>max){
									end=max;
									last = true;
								}
				           		while(i<=end){
				           				readimagefile(loc[i],px1,py1,px1+147,py1+147);
										outtextxy(px1+164+10,py1+3,a2[i].item_name);
										char buf[50];
										sprintf(buf,"%.2f",a2[i].price);
										outtextxy(px1+164+10,py1+3+45,buf);
										outtextxy(px1+164+10,py1+3+84,"description ");
										sprintf(buf,"%d",a2[i].quantity);
										outtextxy(px1+165+10,py1+3+168,buf);
				
										px1+=419;
										if(px1+419>1360){
											px1=50;
											py1+=124+147;
										}
										i++;
								   }	
								}
								readimagefile("images\\homepage\\footer.jpg",0,639,window_x,window_y);
								delay(100);
			      		}
					}
				}// if the button next
				if(mousex() > bx1 && mousex() < bx1 + 109 && mousey() > by1 && mousey() < by1 + 33 ){
					readimagefile("images\\homepage\\back_button.jpg",bx1, by1, bx1 + 109, by1 + 33);
					while(mousex() > bx1 && mousex() < bx1 + 109 && mousey() > by1 && mousey() < by1 + 33 ){	
					if(GetAsyncKeyState(VK_LBUTTON)){
						if(start>=1){
							last=false;
							start-=6;
							i=start;
							readimagefile("images\\homepage\\guest_homepg.jpg",0,0,window_x,window_y);
								px1=50,py1=113;
								end=start+6;
				           		while(i<end){
				           				readimagefile(loc[i],px1,py1,px1+147,py1+147);
										outtextxy(px1+164+10,py1+3,a2[i].item_name);
										char buf[50];
										sprintf(buf,"%.2f",a2[i].price);
										outtextxy(px1+164+10,py1+3+45,buf);
										outtextxy(px1+164+10,py1+3+84,"description ");
										sprintf(buf,"%d",a2[i].quantity);
										outtextxy(px1+165+10,py1+3+168,buf);
										px1+=419;
										if(px1+419>1360){
											px1=50;
											py1+=124+147;
										}
										i++;
								   }	
							}
							readimagefile("images\\homepage\\footer.jpg",0,639,window_x,window_y);
							delay(100);
			      		}
					}
				}// if the button back
				
				if(logged==0){
					if((mousex()>0 && mousex()<window_x && mousey()>50 && mousey()<window_y-57)||((mousex()>1130 && mousex()<1130+121 && mousey()>8 && mousey()<8+34)))
					{	
						while((mousex()>0 && mousex()<window_x && mousey()>50 && mousey()<window_y-57)||((mousex()>1130 && mousex()<1130+121 && mousey()>8 && mousey()<8+34)))
						{
							if(GetAsyncKeyState(VK_LBUTTON)){  //mistake tya click bhanyena (jata clik gareni state on) ad are you sure ?
								return 444;//login ma click gareni hune vayo 
							}
						}
					}
					
					if(mousex()>1130+121 && mousex()<1296 && mousey()>8 && mousey()<8+34)
					{
						while(mousex()>1130+121 && mousex()<1296 && mousey()>8 && mousey()<8+34)
						{
							if(GetAsyncKeyState(VK_LBUTTON))
							{
								exit(1);	//exit garne yo chai
							}
						}
					}
				}
				if(logged==3){
					cout<<"inside admin\n";
					readimagefile("images\\homepage\\admin_header.jpg",0,0,window_x,50);
					readimagefile("images\\homepage\\footer_edit.jpg",0,639,window_x,window_y);
					if(mousex() > ex1-50 && mousex() < ex1 -50+109 && mousey() > ey1  && mousey() < ey1 + 34){
						while(mousex() > ex1 && mousex() < ex1 + 186 && mousey() > ey1  && mousey() < ey1 + 34){
							if(GetAsyncKeyState(VK_LBUTTON)){
									LIGHTBROWN = COLOR(169, 169, 169);
									setbkcolor(LIGHTBROWN);
									settextstyle(3,0,1);		
									cleardevice();
									
									return 131;
								}		
					    	}
						}	
						else if(mousex() > 1130 && mousex() < 1130+121 && mousey() > 8 && mousey() < 8+34){
						while(mousex() > 1130 && mousex() < 1130+121 && mousey() > 8 && mousey() < 8+34){
							if(GetAsyncKeyState(VK_LBUTTON)){
								return 132;
							}
						}
					}
								
					}
				else if(logged == 1){
					// readimagefile("images\\homepage\\user_loggedin.jpg",0,0,window_x,window_y);
					readimagefile("images\\homepage\\user_header.jpg",0,0,window_x,50);
					if(GetAsyncKeyState(VK_LBUTTON)){
						cout<<"cart\n";
						//checks which cart is clicked-------------------------------
//						cout<<"clicked\n checking the click";
						px1=50,py1=113;
						int items_in_cart=0;
						strcpy(file,"users\\");
						strcat(file,logged_in);
						strcat(file,".dat");
						fstream fin(file,ios::in | ios::binary);
						fin.read((char*)&a2[i],sizeof(a2[i]));
						while(fin){
							items_in_cart++;
							fin.read((char*)&a2[i],sizeof(a2[i]));						
						}
						fin.close();
						
						i=start;
						while(i<end+1){
//					cout<<"clicked at "<<cout<<a2[i].item_name<<" ?"<<endl;
							if(mousex() > px1+256 && mousex() < px1+256+88 && mousey() > py1+167 && mousey() < py1+167+27){
								if(items_in_cart<6){
									int itfx=300,itfy=639;
								outtextxy(300,639,"enter the quantity : ");
								
								quantity=0;
								int j=0;
								while((buf[j]=getch())!=13 && j<=5){ 
									if(buf[j]==8 && j>0){
										j--;
										buf[j]='\0';
										readimagefile("images\\homepage\\item_details_box.jpg",itfx,itfy,itfx+335,itfy+42);
									}
									else{
										j++;
										buf[j]='\0';
									}
									outtextxy(itfx+15,itfy+10, buf);
								}
									buf[j]='\0';
								
								a2[i].quantity = atoi(buf);
								
								Store carto;
								fstream cart(file, ios::in | ios::out | ios::binary | ios::ate);
								if (!cart.is_open()) {
									cerr << "Failed to open cart file." << endl;
								    return 0;
								}
								cart.seekg(0, ios::beg);
								streampos loc;
								bool item_found = false;
								
								while(cart.read((char*)&carto, sizeof(carto))){
									if(strcmp(a2[i].item_code,carto.item_code)==0){
										cout<<"got same code"<<endl;
										carto.quantity+=a2[i].quantity;
										cart.seekp(cart.tellp() - sizeof(carto));
           								cart.write((char*)&carto, sizeof(carto));
								        cout << "Updated item: " << carto.item_name << " Quantity: " << carto.quantity << endl;
								        item_found = true;
								        break;
									}
									
								}
								cart.close();
								
								if(!item_found){
									cout<<"no same code\n";
									fstream fout(file,ios::app);
									fout.write((char*)&a2[i],sizeof(a2[i]));
									fout.close();
									outtextxy(300,639,"press any key to continue add_to_cart");	
									getch();
									readimagefile("images\\homepage\\footer.jpg",0,639,window_x,window_y);	
								}
								}
								else{
									outtextxy(300,639,"cart is full !!");
									getch();
								}
								break;
							}
							
							px1+=419;
							if(px1+419>1360){
							px1=50;
							py1+=124+147;
							}
							i++;
						}
					}
					if(mousex() > ex1+907 && mousex() < ex1+907 + 109 && mousey() > ey1-642  && mousey() < ey1 -642 + 33){ //cart button
						while(mousex() > ex1+907 && mousex() < ex1+907 + 109 && mousey() > ey1-642  && mousey() < ey1 -642 + 33){
							if(GetAsyncKeyState(VK_LBUTTON)){
								delay(100);
									readimagefile("images\\homepage\\cart_bg.jpg",0,0,window_x,window_y);
									file[30];
									strcpy(file,"users\\");
									strcat(file,logged_in);
									strcat(file,".dat");
									fstream fio(file,ios::in | ios::binary);
									Store a2[20];
									char loc1[30][100];
									i=0;
									int cx1=125,cy1=152;
									char buf[50];
									double total;
									LIGHTBROWN = COLOR(204, 204, 204);
									setbkcolor(LIGHTBROWN);
									settextstyle(3,0,1);
									fio.read((char*)&a2[i],sizeof(a2[i]));
									while(fio){
//										sprintf(buf,"%d",i+1);
										outtextxy(cx1-16,cy1+1,buf);
										strcpy(loc1[i],"images\\clothes\\");
										strcat(loc1[i],a2[i].item_code);
										strcat(loc1[i],".jpg");
										if(cy1<window_x-53){
										readimagefile(loc1[i],cx1+19,cy1,cx1+100,cy1+100);
										outtextxy(cx1+140,cy1+3,a2[i].item_name);
										sprintf(buf,"%f",a2[i].price);
										outtextxy(cx1+140,cy1+41,buf);
										total+=a2[i].price;
										sprintf(buf,"%d",a2[i].quantity);
										outtextxy(cx1+140,cy1+76+3,buf);
											cx1+=593;
										if(cx1>window_x){
											cx1=125;
											cy1+=170;
										}
										}
										
										i++;
										
										fio.read((char*)&a2[i],sizeof(a2[i]));
									}
									fio.close();
									
								while(1){
									
									if(mousex() > 1172 && mousex() < 1172+109 && mousey() > 651 && mousey() < 651+33){ //cartbutton
										while(mousex() > 1172 && mousex() < 1172+109 && mousey() > 651 && mousey() < 651+33){
											if(GetAsyncKeyState(VK_LBUTTON)){
												int itfx=300,itfy=639;
												int billx=337,billy=296;
												char buf[30];
												int hr,min,sec,year,month,date;
												char day[10];
												double total=0;
												setbkcolor(WHITE);
												setcolor(0);
												cout << "Buying process initiated..." << endl;

								                ifstream cart(file, ios::in | ios::binary);
								                if (!cart.is_open()) {
								                    cerr << "Failed to open cart file." << endl;
								                    return 0;
								                }
												
												ofstream fout("data\\state.txt",ios::out | ios::app);
															hr = timeinfo->tm_hour;
			        										min = timeinfo->tm_min;
			        										sec = timeinfo->tm_sec;
			      											year = timeinfo->tm_year + 1900;  // tm_year is years since 1900
			       											month = timeinfo->tm_mon + 1;     // tm_mon is months since January (0-11)
			        										date = timeinfo->tm_mday;
			        										strftime(day, sizeof(day), "%A", timeinfo);
			        										
										        fout << date << "/" << month << "/" << year << endl;
												fout << day << endl;
												fout << hr << " : " << min << endl;
												fout <<logged_in<< endl;
												
								                Store carto, itemso;
								                cart.seekg(0, ios::beg);
												readimagefile("images\\homepage\\BILL.jpg",283,70,996,684);
//												259,0,1036,901
												outtextxy(381,202,logged_in);		//name
												sprintf(buf,"%d/%d/%d",date,month,year);
												outtextxy(381,229,buf);
								                while (cart.read((char*)&carto, sizeof(carto))) {
								                    cout << "Processing item from cart: " << carto.item_name << endl;
													
													
								                    fstream items("data\\items.dat", ios::in | ios::out | ios::binary | ios::ate);
								                    if (!items.is_open()) {
								                        cerr << "Failed to open items file." << endl;
								                        cart.close();
								                        return 0;
								                    }
								
								                    items.seekg(0, ios::beg);
								                    streampos loc;
								                   	bool item_found = false;
								
								                    while (items.read((char*)&itemso, sizeof(itemso))) {
								                        if (strcmp(carto.item_code, itemso.item_code) == 0){
															
															if(carto.quantity<itemso.quantity){
																fout<<carto.item_name<<endl<<carto.price<<endl<<carto.quantity<<endl<<carto.price*carto.quantity<<endl;
									                        	outtextxy(billx,billy,carto.item_name);		// billx=337,billy=296;
									                        	sprintf(buf,"%.2f",carto.price);
									                        	outtextxy(billx+350,billy,buf);		//rate
									                        	sprintf(buf,"%d",carto.quantity);
									                        	outtextxy(billx+468,billy,buf);
									                        	sprintf(buf,"%.2f",(carto.quantity*carto.price));
									                        	outtextxy(billx+550,billy,buf);
									                        	billy+=20;
									                        	
																cout<<carto.item_name<<endl<<carto.quantity<<endl<<carto.price<<endl;
																total+=carto.price*carto.quantity;
																
								                           		itemso.quantity-=carto.quantity;
           														items.seekp(items.tellp() - sizeof(itemso));
           														items.write((char*)&itemso, sizeof(itemso));
//								                           		cout << "Updated item: " << itemso.item_name << " Quantity: " << itemso.quantity << endl;
								                            	item_found = true;
								                            	break;
															}
															else{
																outtextxy(cx1+50,cy1-50,"sorry, the product is out of stock !!");
//																break;
															}
								                        }
								                    }
								                    
								                	
								                   if(!item_found) {
								                        cout << "Item " << carto.item_name << " not found in items file." << endl;
								                        outtextxy(itfx,itfy,"Item ");
								                        itfx+=40;
								                        outtextxy(itfx,itfy,carto.item_name);
								                        itfx+=40;
								                		outtextxy(itfx,itfy," not found ");
//								                		fout<<"item : "<<carto.item_name<<" not found !"<<endl;
								                    }
								                    items.close();
								                }
								                fout<<"total\n"<<total<<endl;
												sprintf(buf,"%.2f",total);
												outtextxy(billx+350,billy,"TOTAL");
												outtextxy(billx+550,billy,buf);
								                fout.close();
								                cart.close();
									  			delay(200);
//									  			Clear the cart file
												ofstream fclear(file, ios::out | ios::trunc);
												if (fclear.is_open()) {
												    fclear.close();
												} else {
												    cout << "Failed to clear the cart file." << endl;
												}
												cout << "Buying process completed.\n";
													getch();
										  			return 2211;
									  		}
										}
									}
								if(mousex() > 12 && mousex() < 12+109 && mousey() > 651 && mousey() < 651+33){
									while(mousex() > 12 && mousex() < 12+109 && mousey() > 651 && mousey() < 651+33){
										if(GetAsyncKeyState(VK_LBUTTON)){
											return 2211;
										}
									}
								}

							}//end of while
								
						}
					}
						
					}
					else if(mousex() > 1130 && mousex() < 1130+121 && mousey() > 8 && mousey() < 8+34){
						while(mousex() > 1130 && mousex() < 1130+121 && mousey() > 8 && mousey() < 8+34){
							if(GetAsyncKeyState(VK_LBUTTON)){
								return 0;
							}
						}
					}
				}
			}
			
		}
		
		int item_details()	//	add items
		{
			
			readimagefile("images\\homepage\\admin_dashboard_add.jpg",0,0,window_x,window_y);
			int i=0,fx1=660,fy1=183;
			while(1){
				if(kbhit()){
					item_name[i]=getch();
					if(item_name[i]==27){
						return 220;
					}
					if(item_name[i]!=13 && i<=19){
						if(item_name[i]==8 && i>0){
							i--;  
							item_name[i]='\0';
						}
						else if (item_name[i] != 8) {
							i++;
							item_name[i]='\0';
						}
						readimagefile("images\\homepage\\item_details_box.jpg",fx1+15,fy1+13,fx1+335,fy1+40);
						outtextxy(fx1+15,fy1+13, item_name);
					}
					else{
						item_name[i]='\0';
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()>520 && mousex()<702 && mousey()>463 && mousey()<508){
						return 220;
					}
				}
			}
			
			i=0,fy1=252;
			while ((item_code[i] = getch()) != 13 && i <=4) { // Assuming 13 is Enter key
			if(item_code[i]==27){
				return 220;
			}
            if (item_code[i] == 8 && i > 0) { // Backspace handling
                i--;
                item_code[i] = '\0';
                readimagefile("images\\homepage\\item_details_box.jpg", fx1+15,fy1+13,fx1+335,fy1+40); // Clear the text box area
            } else {
                i++;
                item_code[i] = '\0';
            }
            outtextxy(fx1+15,fy1+13, item_code);
        }
        item_code[i] = '\0'; // Null terminate the item_code
        cout << "Item Code: " << item_code << endl;
        cout<<logged<<endl;
        
			i=0,fy1=323;
			quantity=0;
			while((buf[i]=getch())!=13 && i<=5){ 
				if(buf[i]==8 && i>0){
					i--;
//					quantity = (quantity - buf[i] - '0')/10;
					buf[i]='\0';
					readimagefile("images\\homepage\\item_details_box.jpg",fx1+15,fy1+13,fx1+335,fy1+40);
				}
				else{
//					quantity = quantity*10 + buf[i] - '0';
					i++;
					buf[i]='\0';
				}
				outtextxy(fx1+15,fy1+13, buf);
			}
			for(int j=i;j<20;j++){
				buf[j]='\0';
			}
			quantity = atoi(buf);
			cout<<endl<<quantity<<endl;

			i=0,fy1=393;
			buf[30];
			price=0;
			while(1){
				if(kbhit()){
					buf[i]=getch();
				if(buf[i]!=13 && i<=10){
					if(buf[i]==8 && i>0){
						i--;  
						buf[i]='\0';
						readimagefile("images\\homepage\\item_details_box.jpg",fx1+15,fy1+13,fx1+335,fy1+40);
					}
					else{
						i++;
						buf[i]='\0';
					}
					outtextxy(fx1+15,fy1+13, buf);
					}
					else{
						buf[i]='\0';
						break;
					}
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex() > 831 && mousex() <831 + 180 && mousey() > 467  && mousey() < 467 + 43){
						break;
					}
				}
			}
		price = atof(buf);
		cout<<price;
	}
		
		int updated_item(){
			bool found = false;
			streampos loc;
			
			int i=0, fx1=728, fy1=125; //left top
			readimagefile("images\\homepage\\admin_dashboard_update.jpg",0,0,window_x,window_y);
			
			while(1){
			if(kbhit()){
				item_code[i] = getch();
				if(item_code[i]!= 13 && i < 19){
					if (item_code[i] == 8 && i > 0) { // Backspace handling
		                i--;
		                item_code[i] = '\0';
		                readimagefile("images\\homepage\\item_details_box.jpg", fx1+15, fy1+10, fx1 + 200, fy1 + 30); // Clear the text box area
		            }
					else {
		                i++;
		                item_code[i] = '\0';
		            }
		            outtextxy(fx1 + 15, fy1 + 10, item_code);
				}
		       	else{
		       		break;
				   }
			}
			if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex() > fx1+15 && mousex() < fx1 + 200 && mousey() > fy1+10 && mousey() < fy1 + 30){
						break;
					}
					else{
						return 0;
					}
				}
		}
        item_code[i] = '\0'; // Null terminate the item_code
        cout << "Item Code: " << item_code << endl;
        
        Store a2;
		fstream fin("data\\items.dat",ios::in | ios::out | ios::binary | ios::ate);
		
		fin.seekg(0,ios::beg);
		fin.read((char*)&a2,sizeof(a2));
			while(fin){
				if(strcmp(a2.item_code,item_code)==0){
					cout<<"found !!!";
					found=true;
					loc=fin.tellg()-sizeof(a2);
					break;
				}
				fin.read((char*)&a2,sizeof(a2));
			}
			if(found){
				int txx=500,tyy=112+219+10;
				outtextxy(txx, tyy, a2.item_name);
	            tyy += 70;
	            sprintf(buf, "%d", a2.quantity);
	            outtextxy(txx, tyy, buf);
	            tyy += 70;
	            sprintf(buf, "%.2f", a2.price);  // Corrected format string
	            outtextxy(txx, tyy, buf);
				while(1){
					delay(100);
						outtextxy(500,200,"Enter what do you want to update (1/2/3/4) : "); 
							int i=0,fx1=661,fy1=112;
							while(true){
								if(kbhit()){
									choice = getch();
									break;
								}
								if(GetAsyncKeyState(VK_LBUTTON)){
//									if(mousex() > ____ && mosuey() > ____ && mousey() < _____ && mousex() < ____){
										choice = '4';
										break;
//									}
								}
								
							}
						switch(choice){
							case '1':{
								outtextxy(500,200,"enter the name u wanna update : ");
								
									while((a2.item_name[i]=getch())!=13 && i<=19){
										if(a2.item_name[i]==8 && i>0){
											i--;
											a2.item_name[i]='\0';
											readimagefile("images\\homepage\\item_details_box.jpg",fx1+268+15,fy1+219+10,fx1+268+15+265,fy1+219+10+30);
										}
										else{
											i++;
											a2.item_name[i]='\0';
										}
										outtextxy(fx1+268+15,fy1+219+10, a2.item_name);
									}
									a2.item_name[i] = '\0';
								break;
							}
							case '2':{
								outtextxy(500,200,"enter the quantity u wanna update : ");
								cout<<"\nenter quantity \n";
							a2.quantity=0;
							i=0;
							while((buf[i]=getch())!=13 && i<=5){ 
								if(buf[i]==8 && i>0){
									i--;  
				//					quantity = (quantity - buf[i] - '0')/10;
									buf[i]='\0';
									readimagefile("images\\homepage\\item_details_box.jpg",fx1+296+15,fy1+289+10,fx1+296+15+235,fy1+289+10+30);
								}
								else{
				//					quantity = quantity*10 + buf[i] - '0';
									i++;
									buf[i]='\0';
								}
								outtextxy(fx1+296+15,fy1+289+10, buf);	//quantity in screen
							}
							for(int j=i;j<20;j++){
								buf[j]='\0';
							}
							a2.quantity = atoi(buf);
							cout<<endl<<a2.quantity<<endl;
							break;
							}
							case '3':{
								outtextxy(500,200,"Enter the price u wanna update : ");
								cout<<"\nenter price \n";
								i=0;
								while((buf[i]=getch())!=13 && i<=5)
								{
									if(buf[i]==8 && i>0)
									{
										i--;  
					//					a2.quantity = (a2.quantity - buf[i] - '0')/10;
										buf[i]='\0';
										readimagefile("images\\homepage\\item_details_box.jpg",fx1+268+15,fy1+359+10,fx1+268+15+265,fy1+359+10+30);
									}
									else
									{
					//					a2.quantity = a2.quantity*10 + buf[i] - '0';
										i++;
										buf[i]='\0';
									}
									outtextxy(fx1+268+15,fy1+359+10, buf);
								}
								buf[i]='\0';
								a2.price = atof(buf);
								cout<<endl<<a2.price<<endl;
								break;
							}
							case '4':{
								outtextxy(fx1,fy1-30,"Item updated Sucessfully !!!!! ");
								fin.seekp(loc);
								fin.write((char*)&a2,sizeof(a2));
								fin.close();
								return 0;
								break;
							}
							default :{
								outtextxy(fx1,fy1-60,"invalid choice");
								break;
							}
						}
					}//end of while
			}
			fin.close();
		}
		
	void display_list() {
	
    cout << "here\n";
    int txx = 262, tyy = 110;
	int count=0;
    char ch;
    while(true){
    	LIGHTBROWN = COLOR(128, 128, 128);
		setbkcolor(LIGHTBROWN);
    	Store a2;
		readimagefile("images\\homepage\\admin_dashboard_viewitemlist.jpg",0,0,window_x,window_y);
	    ifstream fin("data\\items.dat", ios::in | ios::binary);
	    if (!fin) {
	        cout << "Error opening file" << endl;
	        return;
	    }
	        int i = 1;
	        char buf[50];  // Increased size to accommodate larger strings
	        fin.seekg(0, ios::beg);
	        fin.read((char*)&a2, sizeof(a2));
	        while (fin){
	        	cout<<"show from file\n";
	            sprintf(buf, "%d", i);
	            outtextxy(txx - 15, tyy, buf);
	            outtextxy(txx, tyy, a2.item_name);
//	            tyy+=25;
	            outtextxy(txx, tyy+25, a2.item_code);
	            sprintf(buf, "%d", a2.quantity);
//	            tyy+=25;
	            outtextxy(txx, tyy+50, buf);
	            sprintf(buf, "%.2f", a2.price);  // Corrected format string
//	            tyy+=25;
	            outtextxy(txx, tyy+75, buf);
	            i++;
				txx+=352;
				
				if(txx>window_x){
					txx=262;
					tyy+=178;
				}
	            fin.read((char*)&a2, sizeof(a2));  // Read next record
	        }
			fin.close();
			readimagefile("images\\homepage\\display_header.jpg",0,0,window_x,50);
			readimagefile("images\\homepage\\display_footer.jpg",0,639,window_x,window_y);
//			cout<<"click me: \n";
	        ch=getch();
	        if(ch=='w'){
	        	tyy = 110;//4
	        	count++;
	        	tyy -= 178*count;
			}
			else if(ch=='s'){
				tyy = 110;
				if(count!=0){
					count--;
				}
				tyy -= 178*count;
			}
			else if(ch==27){
				
				break;
			}
			
			txx = 262;
    }
}
	
		void delete_item(){
			int found = false;
			
			readimagefile("images\\homepage\\admin_dashboard_delete.jpg",0,0,window_x,window_y);
			int i=0, fx1=657, fy1=213;
			
		while(1){
			if(kbhit()){
				item_code[i] = getch();
				if(item_code[i]!= 13 && i < 19){
					if (item_code[i] == 8 && i > 0) { // Backspace handling
		                i--;
		                item_code[i] = '\0';
		                readimagefile("images\\homepage\\item_details_box.jpg", fx1+15, fy1+10, fx1 + 340, fy1 + 40);// Clear the text box area
		            } else {
		                i++;
		                item_code[i] = '\0';
		            }
		            outtextxy(fx1 + 15, fy1 + 10, item_code);
				}
				else{
					break;
				}
				if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex()>520 && mousex()<702 && mousey()>463 && mousey()<508){
						return;
					}
					
				}
			}
			if(GetAsyncKeyState(VK_LBUTTON)){
					if(mousex() > fx1 && mousex() < fx1 + 355 && mousey() > fy1 && mousey() < fy1 + 43){
						break;
					}
					else{
						return;
					}
				}
		}
		
        item_code[i] = '\0'; // Null terminate the item_code
        cout << "Item Code: " << item_code << endl;
			
			Store a2;
			
			ifstream fin("data\\items.dat",ios::in  | ios::binary);
			fin.seekg(0,ios::beg);
			ofstream fout("data\\temp.dat",ios::out | ios::binary);
			fin.read((char*)&a2,sizeof(a2));
			while(fin){
				if(strcmp(a2.item_code,item_code)==0){
					cout<<"found !!!";
					found=true;
				}
				else{
					fout.write((char*)&a2,sizeof(a2));
				}
				
				fin.read((char*)&a2,sizeof(a2));
			}
			fout.close();
			fin.close();
			
			if(found){
				remove("data\\items.dat");
				rename("data\\temp.dat","data\\items.dat");
				outtextxy(fx1-25, fy1+225,"item deleted sucessfully!!\n");
			}
			else{
				remove("data\\temp.dat");
				outtextxy(fx1-25, fy1+225,"item not found\n");
			}
		}
		
	void state(){
		string check;
//		int stx=235,sty=125;
		int year,month,date;
		char day[10];
		year = timeinfo->tm_year + 1900;  // tm_year is years since 1900
		month = timeinfo->tm_mon + 1;     // tm_mon is months since January (0-11)
		date = timeinfo->tm_mday;
		strftime(day, sizeof(day), "%A", timeinfo);
		char miti[15];
		sprintf(miti,"%d/%d/%d",date,month,year);
		char stat[30];
		while(1){
		int stx=236,sty=169;
		ifstream fin("data\\state.txt",ios::in);
		fin.seekg(0,ios::beg);
		readimagefile("images\\homepage\\admin_dashboard_statement.jpg",0,0,window_x,window_y);
//		getline(fin,check);
		while(getline(fin,check)){
			cout<<"checking next buy\n\n";
			
			if(miti!=check){
				while(getline(fin,check)){
					if(miti==check){
						break;
					}
				}
			}
			
			if(!fin){
//				outtextxy(300,200,"date not found");
				getch();
				break;
			}
			else{
				setbkcolor(BLACK);
	//			cout<<check<<endl;
				strncpy(stat, check.c_str(), sizeof(stat) - 1);
				outtextxy(stx+140,sty,stat);
				getline(fin,check);
				strncpy(stat, check.c_str(), sizeof(stat) - 1);
				outtextxy(stx+220,sty,stat);
				getline(fin,check);
				strncpy(stat, check.c_str(), sizeof(stat) - 1);
				outtextxy(stx+140,sty+20,stat);
				getline(fin,check);
				strncpy(stat, check.c_str(), sizeof(stat) - 1);
				outtextxy(stx,sty,stat);
	//			sty+=20;
				getline(fin,check);
				while(check!="total"){
					cout<<"checking total\n\n";
					strncpy(stat, check.c_str(), sizeof(stat) - 1);
					outtextxy(stx+327,sty,stat);
					getline(fin,check);
					strncpy(stat, check.c_str(), sizeof(stat) - 1);
					outtextxy(stx+755,sty,stat);
					getline(fin,check);
					strncpy(stat, check.c_str(), sizeof(stat) - 1);
					outtextxy(stx+875,sty,stat);
					getline(fin,check);
					
					strncpy(stat, check.c_str(), sizeof(stat) - 1);
					outtextxy(stx+930,sty,stat);
					getline(fin,check);
					sty+=20;
				}
				setbkcolor(RED);
				if(check=="total"){
					cout<<"found total\n";
					getline(fin,check);
					strncpy(stat, check.c_str(), sizeof(stat) - 1);
					outtextxy(stx+327,sty,"TOTAL");
					outtextxy(stx+930,sty,stat);
					sty+=20;
				}
			}
		}
		fin.close();
		while(1){
			cout<<"on the loop please click the search for me : \n";
			if(GetAsyncKeyState(VK_LBUTTON)){
				if(mousex()>1076 && mousey()>5 && mousex()<1194 && mousey()<44){
					rectangle(1076-10,5-2,1194+3,44+2);
					int i=0;
					while(1){
						if(kbhit()){
							
							miti[i]=getch();
							if(miti[i]!=13 && i<=19){
								if(miti[i]==8 && i>0){
									i--;  
									miti[i]='\0';
								}
								else if (miti[i] != 8) {
									i++;
									miti[i]='\0';
								}
								readimagefile("images\\homepage\\state_dhaka.jpg",1063,66,1063+300,66+30);
								outtextxy(1063,66, miti);
							}
							else
							{
								miti[i]='\0';
								break;
							}
						}
					}
					break;
				}
				else if(mousex()>1220 && mousey()>4 && mousex()<1260 && mousey()<43){
					return;
				}
				else{
					
				}
			}
		}
		
		}
	}
	
};

int main(){
	Store guest(0),user(1),admin(3);
		//chaange window_x in whole code for adjusting window
	initwindow(1293,696," Fashion Store ",0,0);
//	initwindow(2586,1392," Fashion Store ",50,0);
	
//	initwindow(3400,1908," ");
	Account person;
	fstream fio;
	int opt=0;
	while(1){
		opt=guest.display();
		if(opt==444){
			opt=guest.startup_page();	
		}
		readimagefile("images\\login_page\\login_page.jpg",0,0,window_x,window_y);
		switch(opt){
			case 11:{
				cleardevice();
				readimagefile("images\\login_page\\login_page.jpg",0,0,window_x,window_y);
				opt=person.create();
				
				if(opt!=210){
					fio.open("data.dat",ios::app);
					fio.write((char*)&person,sizeof(person));
					fio.close();
				}
				break;
			}
			case 12:{
				cleardevice();
				readimagefile("images\\login_page\\login_page.jpg",0,0,window_x,window_y);
				opt=person.login();
//				t.set_name(person.get_name());
				if(opt==2211){
					cout<<"welcome to fashion store !!\n";
					cleardevice();
					while(opt==2211){
						cout<<"displaying\n";
						opt=user.display();
						cout<<"checking if the buying process 2299\n";
					}
				}
				else if(opt==2213){
					cout<<"welcome admin!!\n";
					choice=0;
					while(choice!=132){
						
						choice=admin.display();
						if(choice==131){
								cout<<"enter your choice to \n1.add\n2.delete\n3.update\n4.view\n5.exit";
							while(1){
								admin.check_log();
								int ex1=10,ey1=112;
								readimagefile("images\\homepage\\admin_dashboard.jpg",0,0,window_x,window_y);
								if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1  && mousey() < ey1 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1  && mousey() < ey1 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
											opt=admin.item_details();
											if(opt!=220){
												fio.open("data\\items.dat",ios::app);
												cout<<"fileopened";
												fio.write((char*)&admin,sizeof(admin));
												cout<<"filewrite";
												fio.close();
											}
										}
										break;
									}
								}
								
								else if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58 && mousey() < ey1 + 58 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58  && mousey() < ey1 + 58 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
											admin.delete_item();
										}
									}
								}
								else if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 116 && mousey() < ey1 + 116 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 116 && mousey() < ey1 + 116 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
											admin.updated_item();
										}
									}
								}
								else if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*3 && mousey() < ey1 + 58*3 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*3 && mousey() < ey1 + 58*3 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
											admin.display_list();
										}
									}
								}
								else if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*4 && mousey() < ey1 + 58*4 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*4 && mousey() < ey1 + 58*4 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
													admin.state();
											//statement
										}}}
								else if(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*5 && mousey() < ey1 + 58*5 + 43){
									while(mousex() > ex1 && mousex() < ex1 + 180 && mousey() > ey1 + 58*5 && mousey() < ey1 + 58*5 + 43){
										if(GetAsyncKeyState(VK_LBUTTON)){
											delay(300);
											break;
										}
									}
									break;
								}
								cout<<"exiting\n";
							}
						} 
//								admin.display_list();
								
								cout<<"exiting\n";
							}
							//end of while loop 	
						}
					
				}	//end of logged in switch
				break;
			
			}
		}
	}//end of while

//}
