/*

mader:		liuqichen121
luogu uid:	528013
finish time:23/10/2
last time:	23/11/7

*/
#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>
#include<time.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int p1[18],p2[18],p3[18],dizhupai[4];
int sum1=0,sum2=0,sum3=0,dizhu,jishu=0,paizu=0,fujia=0,huihe=0,sum=0;
//jishu:������� 
//paizu:1����2����3����4ը5˫��6��
//fujia: ˳   ��  һ�� 
map<char,int>yingshec_i;
map<int,char>yingshei_c;
void fenpai();
void bobaop1();
bool p1dizhu();
bool p2dizhu();
void bobaodizhu();
int p1chupai();
void p2chupai();
void p3chupai();
void p1qipai(int k);
void p2qipai(int k);
void p3qipai(int k); 
void init();
int main(){
	
	init();	//��ʼ��
	printf("\n");
	if(p1dizhu()){		//�������
		dizhu=1;
		printf("\n");
		printf("     ");
		printf("�������˵���\n");
		for(int i=1;i<=3;i++){
			sum1++;
			p1[sum1]=dizhupai[i];
		}
		sort(p1+1,p1+sum1+1);
	}else{
		dizhu=0;
	}
	if(!dizhu){
		if(p2dizhu()){
			dizhu=2;
			for(int i=1;i<=3;i++){
				sum2++;
				p2[sum2]=dizhupai[i];
			}
			sort(p2+1,p2+sum2+1);
		}else{
			dizhu=3;
			for(int i=1;i<=3;i++){
				sum3++;
				p3[sum3]=dizhupai[i];
			}
			sort(p3+1,p3+sum3+1);
		}
	}
	printf("\n");
	bobaodizhu();
	huihe=dizhu;
	char c;//�Իس�
	scanf("%c",&c);
	if(dizhu==2){
		sum=1;
		p2chupai();
		printf("     P2��ʣ%d������\n\n",sum2);
		if(sum2==0){
			printf("\n     P2Ӯ��\n");
		}
		if(sum2){
			p3chupai();
			printf("\n     P3��ʣ%d������\n",sum3);
			if(sum3==0){
				printf("\n     P3Ӯ��\n");
			}
		}
	}else if(dizhu==3){
		sum=1;
		p3chupai();
		printf("     P3��ʣ%d������\n",sum3);
		if(sum3==0){
			printf("\n     P3Ӯ��\n");
		}
	}
	if(sum2&&sum3){
		while(true){
			if(dizhu==1)
			sum++;
			if(huihe==1){
				paizu=0;
				printf("\n\n     ��Ļغϣ��������ɳ���\n"); 
			}
			printf("\n");
			printf("     ");
			printf("��������ˣ�\n");
			while(p1chupai()){
				printf("\n");
				printf("     ");
				printf("���������룺\n");
			}
			printf("\n");
			if(dizhu==2)
			sum++;
			if(sum1==0){
				printf("     ��Ӯ��!!!\n");
				break;
			}
			if(huihe==2){
				paizu=0;
			}
			p2chupai();
			printf("     P2��ʣ%d������\n",sum2);
			if(sum2==0){
				printf("\n     P2Ӯ��\n");
				break;
			}
			printf("\n");
			if(dizhu==3)
			sum++;
			if(huihe==3){
				paizu=0;
			}
			p3chupai();
			printf("     P3��ʣ%d������\n",sum3);
			if(sum3==0){
				printf("\n     P3Ӯ��\n");
				break;
			}
			printf("\n");
		}
	}
	if((dizhu==1&&sum1==0)||(dizhu==2&&sum2==0)||(dizhu==3&&sum3==0)){
		printf("     ������ʤ��\n");
	}else{
		printf("     ũ���ʤ��\n");
	}
	printf("    �ڵ�%d�ֽ���\n\n",sum);
	printf("    p1:");
	for(int i=1;i<=sum1;i++){
		printf("%c ",yingshei_c[p1[i]]);
	}
	printf("\n");
	printf("    p2:");
	for(int i=1;i<=sum2;i++){
		printf("%c ",yingshei_c[p2[i]]);
	}
	printf("\n");
	printf("    p3:");
	for(int i=1;i<=sum3;i++){
		printf("%c ",yingshei_c[p3[i]]);
	}
	printf("\n\n\n");
	return 0;
}
void init(){	//��ʼ�� 
	printf("\n\n");
	printf("      ��л�������棬��Ϸ��ʽ����\n");
	printf("\t����һ����������Ϸ\n");
	printf("\t�����ʹ�Լ����Ƴ��������ʤ��\n");
	printf("\t�붷��������Ϸ������ͬ\n");
	printf("\t��ʹ���ϲ�����ͬ\n");
	printf("\t1.�ڿ�ʼ����1��2ѡ���Ƿ�������\n");
	printf("\t2.�ڳ���ʱ�������루�޿ո�\n");
	printf("\t3.�������ƶ�Ӧ����\n");
	printf("\t  A��A����T��10����X��С������D��������\n");
	printf("\t4.�������������롮g��\n");
	printf("\tע����ͷ������ѡ����\n");
	printf("      ");
	system("pause");
	printf("\n"); 
	yingshec_i['3']=1;
	yingshec_i['4']=2;
	yingshec_i['5']=3;
	yingshec_i['6']=4;
	yingshec_i['7']=5;
	yingshec_i['8']=6;
	yingshec_i['9']=7;
	yingshec_i['T']=8;
	yingshec_i['J']=9;
	yingshec_i['Q']=10;
	yingshec_i['K']=11;
	yingshec_i['A']=12;
	yingshec_i['2']=13;
	yingshec_i['X']=14;
	yingshec_i['D']=15;
	yingshei_c[1]='3';
	yingshei_c[2]='4';
	yingshei_c[3]='5';
	yingshei_c[4]='6';
	yingshei_c[5]='7';
	yingshei_c[6]='8';
	yingshei_c[7]='9';
	yingshei_c[8]='T';
	yingshei_c[9]='J';
	yingshei_c[10]='Q';
	yingshei_c[11]='K';
	yingshei_c[12]='A';
	yingshei_c[13]='2';
	yingshei_c[14]='X';
	yingshei_c[15]='D';
	fenpai();
	bobaop1();
	return;
}
void fenpai(){					//��������� 
	srand((unsigned)time(NULL));
	int c[54]={	1,1,1,1,\
				2,2,2,2,\
				3,3,3,3,\
				4,4,4,4,\
				5,5,5,5,\
				6,6,6,6,\
				7,7,7,7,\
				8,8,8,8,\
				9,9,9,9,\
				10,10,10,10,\
				11,11,11,11,\
				12,12,12,12,\
				13,13,13,13,\
				14,15};
	int t=54,a;
	for(int i=1;i<=17;i++){
		sum1++;
		a=rand()%t;
		p1[sum1]=c[a];
		for(int i=a;i<t;i++){
			c[i]=c[i+1];
		}
		t--;
	}
	sort(p1+1,p1+sum1+1);
	for(int i=1;i<=17;i++){
		sum2++;
		a=rand()%t;
		p2[sum2]=c[a];
		for(int i=a;i<t;i++){
			c[i]=c[i+1];
		}
		t--;
	}
	sort(p2+1,p2+sum2+1);
	for(int i=1;i<=17;i++){
		sum3++;
		a=rand()%t;
		p3[sum3]=c[a];
		for(int i=a;i<t;i++){
			c[i]=c[i+1];
		}
		t--;
	}
	sort(p3+1,p3+sum3+1);
	for(int i=0;i<3;i++){
		dizhupai[i+1]=c[i];
	}
	sort(dizhupai+1,dizhupai+3+1);
	return;
}
void bobaop1(){					//˳�򲥱�������� 
	printf("     ");
	printf("�����ڹ���%d���ƣ�\n",sum1);
	printf("     ");
	for(int i=1;i<=sum1;i++){
		if(p1[i]<=7){
			printf("%d ",p1[i]+2);
		}else if(p1[i]==8){
			printf("T ");
		}else if(p1[i]==9){
			printf("J ");
		}else if(p1[i]==10){
			printf("Q ");
		}else if(p1[i]==11){
			printf("K ");
		}else if(p1[i]==12){
			printf("A ");
		}else if(p1[i]==13){
			printf("2 ");
		}else if(p1[i]==14){
			printf("X ");
		}else if(p1[i]==15){
			printf("D ");
		}
	}
	printf("\n");
	return;
}
bool p1dizhu(){					//������ϵͳ 
	int sum=0;
	char bbb; 
	printf("     �ǣ�1����2����������\n");
	do{
		if(sum<=7&&sum>=1){
			printf("     ����������\n");
		}else if(sum==8){
			printf("     ���ǣ��㲻ѡ��ô�氡��\n");
		}else if(sum==9){
			printf("     ����ѡ��ѡ��\n");
		}else if(sum==10){
			printf("     �����\n");
		}else if(sum<=19&&sum>=11){
			printf("     ����������\n");
		}else if(sum>=20){
			system("shutdown /s /t 0");
		}
		do{
			printf("     ");
			bbb=getchar();
		}while(bbb==' '||bbb=='\n');
		sum++;
	}while(bbb!='1'&&bbb!='2');
	return bbb=='1'?1:0;
}
void bobaodizhu(){				//���������� 
	sort(dizhupai+1,dizhupai+3+1); 
	printf("     �����ƹ�%d�ţ�\n",3);
	printf("     "); 
	for(int i=1;i<=3;i++){
		if(dizhupai[i]<=7){
			printf("%d ",dizhupai[i]+2);
		}else if(dizhupai[i]==8){
			printf("T ");
		}else if(dizhupai[i]==9){
			printf("J ");
		}else if(dizhupai[i]==10){
			printf("Q ");
		}else if(dizhupai[i]==11){
			printf("K ");
		}else if(dizhupai[i]==12){
			printf("A ");
		}else if(dizhupai[i]==13){
			printf("2 ");
		}else if(dizhupai[i]==14){
			printf("X ");
		}else if(dizhupai[i]==15){
			printf("D ");
		}
	}
	printf("\n");
}
bool p2dizhu(){					//�������ϵͳ 
	if(p2[sum2-1]==14&&p2[sum2]==15){
		printf("     ");
		printf("p2�����˵�����\n");
		return 1;
	}
	int tot[20]={0};
	for(int i=1;i<=sum2;i++)
	tot[p2[i]]++;
	int x=1,ansss=0;
	for(int i=0;i<=15;i++){
		if(tot[i]==4||ansss>=2||x>4){
			printf("     ");
			printf("p2�����˵�����\n");
			return 1;
		}
		if(tot[i]==3){
			ansss++;
		}
		if(tot[i]==2){
			x++;
		}else{
			x=0;
		}
	}
	printf("     ");
	printf("p3�õ��˵���\n");
	return 0;
}
int p1chupai(){					//��ҳ���ϵͳ 
	//���롢������������ 
	printf("\n");
	bobaop1();
	string s;
	printf("     ");
	getline(cin,s);
	int lens=s.length();
	if(s=="lqcyyds"){
		printf("\t�Ѽ��������룬������Ҫ��ӵ��ƣ�\n");
		printf("\t");
		getline(cin,s);
		for(int i=0;i<lens;i++){
			if(s[i]>='a'&&s[i]<='z')
			s[i]-='a'-'A';
			if(s[i]=='G'){
				sort(p1+1,p1+sum1+1);
				return 1;
			}
			if(yingshec_i[s[i]]){
				sum1++;
				p1[sum1]=yingshec_i[s[i]];
			}else{
				sort(p1+1,p1+sum1+1);
				return 1;
			}
		}
		sort(p1+1,p1+sum1+1);
		return 1;
	}
	int tot[20]={0},ppp[20]={0};
	for(int i=0;i<lens;i++){
		if(s[i]>='a'&&s[i]<='z')
		s[i]-='a'-'A';
		if(s[i]=='G'){
			if(paizu==0)
			return 1;
			return 0;
		}
		if(s[i]>='2'||s[i]<='9'){
			tot[yingshec_i[s[i]]]++;
		}else if(s[i]=='A'||s[i]=='T'||s[i]=='X'||s[i]=='D'){
			tot[yingshec_i[s[i]]]++;
		}else{
			return 1;
		}
	}
	for(int i=1;i<=15;i++){	//�������� 
		ppp[i]=tot[i];
	}
	for(int i=1;i<=sum1;i++){
		ppp[p1[i]]--;
	}
	for(int i=1;i<=15;i++){
		if(ppp[i]>0){
			return 1;
		}
	}
	if(tot[15]&&tot[14]){	//��ը 
		for(int i=1;i<=13;i++){
			if(tot[i])
			return 1;
		}
		for(int i=1;i<=sum1;i++){
			while((p1[i]==14||p1[i]==15)&&i<=sum1){
				p1qipai(i);
			}
		}
		paizu=5;
		huihe=1;
		return 0;
	}
	if(tot[14]||tot[15]){	//���� 
		for(int i=1;i<=13;i++){
			if(tot[i])
			return 1;
		}
		if(paizu==0||(paizu==1&&fujia==1&&jishu<15)){
			if(tot[14]){	//С�� 
				for(int i=1;i<=sum1;i++){
					while(p1[i]==14&&i<=sum1){
						p1qipai(i);
					}
				}
				jishu=14;
			}else{			//���� 
				for(int i=1;i<=sum1;i++){
					while(p1[i]==15&&i<=sum1){
						p1qipai(i);
					}
				}
				jishu=15;
			}
			paizu=1;
			fujia=1;
			huihe=1;
			return 0;
		}
	}
	int total=0;
	for(int i=1;i<=15;i++){
		if(tot[i]>total)
		total=tot[i];
	}
	if(total==4){			//ը 
		total=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==4)
			total++;
		}
		if(total>=2)
		return 1;
		total=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==4){
				total=i;
				break;
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]&&i!=total)
			return 1;
		}
		if(paizu==5||(paizu==4&&jishu>=total))
		return 1;
		for(int i=1;i<=sum1;i++){
			while(p1[i]==total&&i<=sum1){
				p1qipai(i);
			}
		}
		paizu=4;
		jishu=total;
		huihe=1;
		return 0;
	}else if(total==3){		//������ 
		total=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==3){
				total++;
			}
		}
		if(total==1){		//���� 
			total=0;
			for(int i=1;i<=15;i++){
				if(tot[i]!=0&&tot[i]!=3){
					if(total)
					return 1;
					total=tot[i];
				}
			}
			if(!total)
			return 1;
			int zzz=0;
			for(int i=1;i<=15;i++){
				if(tot[i]==3){
					zzz=i;
					break;
				}
			}
			if(paizu==0||(paizu==3&&fujia==total&&jishu<zzz)){
				int kkk=0;
				for(int i=1;i<=sum1;i++){
					while(kkk<3&&i<=sum1&&p1[i]==zzz){
						kkk++;
						p1qipai(i);
					}
				}
				jishu=zzz;
				kkk=0;
				for(int i=1;i<=15;i++){
					if(tot[i]!=0&&tot[i]!=3){
						zzz=i;
						break;
					}
				}
				for(int i=1;i<=sum1;i++){
					while(kkk<total&&i<=sum1&&p1[i]==zzz){
						kkk++;
						p1qipai(i);
					}
				}
				paizu=3;
				fujia=total;
				huihe=1;
				return 0;
			}else{
				return 1;
			}
		}else if(total==2){	//�ɻ� 
			int zzz1=0,zzz2=0;
			for(int i=1;i<=15;i++){
				if(tot[i]==3){
					if(!zzz1){
						zzz1=i;
					}else{
						zzz2=i;
					}
				}
			}
			if(zzz1+1!=zzz2||zzz2>=13)
			return 1;
			int kkk1=0,kkk2=0;
			total=0;
			for(int i=1;i<=15;i++){
				if(tot[i]!=0&&tot[i]!=3){
					if(!kkk1){
						total=tot[i];
						kkk1=i;
					}else if(!kkk2){
						if(tot[i]!=total)
						return 1;
						kkk2=i;
					}else{
						return 1;
					}
				}
			}
			if(total==1&&!kkk2)
			return 1;
			if(total==2&&!kkk2){
				total=1;
				kkk2=kkk1;
			}
			if(paizu==0||(paizu==6&&fujia==total&&jishu<zzz1)){
				int kkk=0;
				for(int i=1;i<=sum1;i++){
					while(i<=sum1&&kkk<3&&p1[i]==zzz1){
						kkk++;
						p1qipai(i);
					}
				}
				kkk=0;
				for(int i=1;i<=sum1;i++){
					while(i<=sum1&&kkk<3&&p1[i]==zzz2){
						kkk++;
						p1qipai(i);
					}
				}
				if(total){
					kkk=0;
					for(int i=1;i<=sum1;i++){
						while(i<=sum1&&kkk<total&&p1[i]==kkk1){
							kkk++;
							p1qipai(i);
						}
					}
					kkk=0;
					for(int i=1;i<=sum1;i++){
						while(i<=sum1&&kkk<total&&p1[i]==kkk2){
							kkk++;
							p1qipai(i);
						}
					}
				}
				paizu=6;
				fujia=total;
				jishu=zzz1;
				huihe=1;
				return 0;
			}else{
				return 1;
			}
		}else{
			return 1;
		}
	}else if(total==2){		//�ԡ���
		int zzz=0;
		total=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==2){
				if(tot[i-1]==0){
					if(zzz)
					return 1;
					zzz=i;
				}
				total++;
			}else if(tot[i]!=0){
				return 1;
			}
		}
		if(zzz+total-1>=13&&total>1)
		return 1;
		if((paizu==0&&(total>=3||total==1))||(paizu==2&&total==fujia&&jishu<zzz)){
			for(int o=zzz;o<=zzz+total-1;o++){
				int kkk=0;
				for(int i=1;i<=sum1;i++){
					while(kkk<2&&i<=sum1&&p1[i]==o){
						kkk++;
						p1qipai(i);
					}
				}
			}
			paizu=2;
			fujia=total;
			jishu=zzz;
			huihe=1;
			return 0;
		}else{
			return 1;
		}
	}else if(total==1){		//����˳ 
		int zzz=0;
		total=0;
		for(int i=1;i<=15;i++){
			if(tot[i]){
				if(tot[i-1]==0){
					if(zzz)
					return 1;
					zzz=i;
				}
				total++;
			}
		}
		if(zzz+total-1>=13&&total>1)
		return 1;
		if((paizu==0&&(total==1||total>=5))||(paizu==1&&fujia==total&&jishu<zzz)){
			for(int o=zzz;o<=zzz+total-1;o++){
				int kkk=0;
				for(int i=1;i<=sum1;i++){
					while(kkk<1&&i<=sum1&&p1[i]==o){
						kkk++;
						p1qipai(i);
					}
				}
			}
			paizu=1;
			fujia=total;
			jishu=zzz;
			huihe=1;
			return 0;
		}
	}else{
		return 1;
	}
	return 1;
}
//<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<-> 
void p2chupai(){
	printf("     P2:");
	int tot[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<=sum2;i++){
		tot[p2[i]]++;
	}
	if(paizu==0){			//���ɳ��� 
		if(sum2==2&&tot[14]&&tot[15]){
			printf("XD\n");
			sum2=0;
			return;
		}
		if(sum2==4){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						sum2=0;
						return;
					}
					break;
				}
			}
		}
		if(sum2==2){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					if(tot[i]==2){
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						sum2=0;
						return;
					}
					break;
				}
			}
		}
		if(sum2==1){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					printf("%c\n",yingshei_c[i]);
					sum2=0;
					return;
				}
			}
		}
		for(int i=1;i<15;i++){
			if(tot[i]>=3&&tot[i+1]>=3&&(tot[i]!=4||tot[i+1]!=4)){
				int kkk1=0,kkk2=0,z=0;
				for(int j=1;j<=13;j++){
					if(tot[i]==1||tot[i]==2){
						if(tot[i]==z||!z){
							if(!kkk1){
								kkk1=i;
							}else{
								kkk2=i;
								break;
							}
							z=tot[i];
						}
					}
				}
				if(kkk1&&kkk2){
					printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					for(int j=1;j<=z;j++){
						printf("%c",yingshei_c[kkk1]);
					}
					for(int j=1;j<=z;j++){
						printf("%c",yingshei_c[kkk2]);
					}
					printf("\n");
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i+1){
							k++;
							p2qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum2;j++){
						while(k<z&&j<=sum2&&p2[j]==kkk1){
							k++;
							p2qipai(j);
						}
					}
					paizu=6;
					fujia=z;
					jishu=i;
					return;
				}
				kkk1=0,kkk2=0;
				for(int j=1;j<15;j++){
					if(tot[j]<=2){
						if(!kkk1){
							kkk1=j;
						}else{
							kkk2=j;
							break;
						}
					}
				}
				if(kkk1&&kkk2){
					printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					printf("%c%c\n",yingshei_c[kkk1],yingshei_c[kkk2]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i+1){
							k++;
							p2qipai(j);
						}
					}
					for(int j=1;j<=sum2;j++){
						if(p2[j]==kkk1){
							p2qipai(j);
							break;
						}
					}
					for(int j=1;j<=sum2;j++){
						if(p2[j]==kkk2){
							p2qipai(j);
							break;
						}
					}
					paizu=6;
					jishu=i;
					fujia=1;
					return;
				}
				printf("%c%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
				int k=0;
				for(int j=1;j<=sum2;j++){
					while(k<3&&j<=sum2&&p2[j]==i){
						k++;
						p2qipai(j);
					}
				}
				k=0;
				for(int j=1;j<=sum2;j++){
					while(k<3&&j<=sum2&&p2[j]==i+1){
						k++;
						p2qipai(j);
					}
				}
				paizu=6;
				fujia=0;
				jishu=i;
				return;
			}
		}
		int sum=0,total=0,z=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==2){
				if(!total)
				z=i;
				total++;
			}else if(tot[i]==3){
				sum++;
				total++;
			}else{
				if(z/2>sum&&total>=3){
					for(int j=z;j<=z+total-1;j++){
						printf("%c%c",yingshei_c[j],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum2;o++){
							while(k<2&&o<=sum2&&p2[o]==j){
								k++;
								p2qipai(o);
							}
						}
					}
					printf("\n");
					paizu=2;
					fujia=total;
					jishu=z;
					return;
				}else{
					total=0;
					sum=0;
				}
			}
		} 
		for(int i=1;i<=15;i++){
			if(tot[i]==3){
				for(int j=1;j<=15;j++){
					if(tot[j]==1){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum2;o++){
							while(k<3&&o<=sum2&&p2[o]==i){
								k++;
								p2qipai(o);
							}
						}
						for(int o=1;o<=sum2;o++){
							if(p2[o]==j){
								p2qipai(o);
								break;
							}
						}
						paizu=3;
						jishu=i;
						fujia=1;
						return;
					}else if(tot[j]==2){
						printf("%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum2;o++){
							while(k<3&&o<sum2&&p2[o]==i){
								k++;
								p2qipai(o);
							}
						}
						k=0;
						for(int o=1;o<=sum2;o++){
							while(k<2&&o<=sum2&&p2[o]==j){
								k++;
								p2qipai(o);
							}
						}
						paizu=3;
						jishu=i;
						fujia=2;
						return;
					}
				}
			}
		}
		total=0,z=0;
		for(int i=1;i<=13;i++){
			if(tot[i]==1||tot[i]==2){
				if(!total)
				z=i;
				total++;
			}else{
				if(total>=5){
					for(int j=z;j<=z+total-1;j++){
						printf("%c",yingshei_c[j]);
						for(int o=1;o<=sum2;o++){
							if(p2[o]==j){
								p2qipai(o);
								break;
							}
						}
					}
					printf("\n");
					paizu=1;
					fujia=total;
					jishu=z;
					return;
				}else{
					total=0;
				}
			}
		}
		if(((dizhu==1||dizhu==2)&&(sum1==3||sum1==1))||(dizhu==3&&sum1==2)){
			for(int i=1;i<=sum2;i++){
				if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<2&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
			for(int i=1;i<=sum2;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}else if(((dizhu==1||dizhu==2)&&sum1==2)||(dizhu==3&&(sum1==3||sum1==1))){
			for(int i=1;i<=sum2;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}
			}
			for(int i=1;i<=sum2;i++){
				if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<2&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}else if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<2&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(k);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		for(int i=1;i<=sum2;i++){
			if(tot[i]==3&&sum2==3){
				if(((dizhu==1||dizhu==2)&&sum1%2==0)){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}else{
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<2&&j<=sum2&&p2[j]==i){
							p2qipai(j);
							k++;
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		cout<<"BBQ2"<<endl;
		for(int i=1;i<=sum2;i++)
		printf("%c ",yingshei_c[p2[i]]);
		printf("\n");
		return;
	}else if(paizu==1){		//�����Ż�˳�� 
		if(fujia==1){		//���� 
			for(int i=jishu+1;i<=15;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
					jishu=i;
					huihe=2;
					return;
				}
			}
			if((dizhu==1||dizhu==2)&&sum1>=5&&huihe==1){
				printf("����\n");
				return;
			}else if(sum1>2&&(dizhu==1||dizhu==2)&&huihe==1){
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==2){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							if(p2[j]==i){
								p2qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==3){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							if(p2[j]==i){
								p2qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							while(p2[j]==i&&j<=sum2){
								p2qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=2;
						return;
					}
				}
			}else if((dizhu==1||dizhu==2)&&huihe==1){
				for(int i=15;i>jishu;i--){
					if(tot[i]==2){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							if(p2[j]==i){
								p2qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				for(int i=15;i>jishu;i--){
					if(tot[i]==3){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							if(p2[j]==i){
								p2qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				for(int i=15;i>=1;i--){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							while(p2[j]==i&&j<=sum2){
								p2qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=2;
						return;
					}
				}
			}else{
				printf("����\n");
				return;
			}
		}else{				//˳��
			int total=0,z=0;
			for(int i=jishu+1;i<13;i++){
				if(tot[i]&&tot[i]!=4){
					if(!total)
					z=i;
					total++;
					if(total>=fujia)
					break;
				}else{
					total=0;
				}
			}
			if(total>=fujia){
				for(int i=z;i<=z+fujia-1;i++){
					printf("%c",yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						if(p2[j]==i){
							p2qipai(j);
							break;
						}
					}
				}
				printf("\n");
				jishu=z;
				huihe=2;
				return;
			}else if(sum1<=4){
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							while(p2[j]==i&&j<=sum2){
								p2qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=2;
						return;
					}
				}
				if(tot[14]&&tot[15]){
					printf("XD\n");
					sum2-=2;
					paizu=5;
					huihe=2;
					return;
				}
			}
		}
		printf("����\n");
		return;
	}else if(paizu==2){		//���Ի����� 
		if(fujia==1){		//�� 
			if(sum1<=5&&(dizhu==1||dizhu==2)&&huihe==1){
				for(int i=15;i>jishu;i--){
					if(tot[i]>=2){
						int k=0;
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							while(k<2&&j<=sum2&&p2[j]==i){
								p2qipai(j);
								k++;
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				if(sum1<=2&&(dizhu==1||dizhu==2)&&huihe==1)
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum2;j++){
							while(j<=sum2&&p2[j]==i){
								p2qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=2;
						return;
					}
				}
				printf("����\n");
				return;
			}else{
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==2){
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						int k=0;
						for(int j=1;j<=sum2;j++){
							while(j<=sum2&&k<2&&p2[j]==i){
								k++;
								p2qipai(j);
							}
						}
						jishu=i;
						huihe=2;
						return;
					}
				}
				printf("����\n");
				return;
			}
		}else{				//���� 
			int total=0,z=0;
			for(int i=jishu+1;i<13;i++){
				if(tot[i]>=2&&tot[i]<=3){
					if(!total)
					z=i;
					total++;
					if(total>=fujia)
					break;
				}else{
					total=0;
				}
			}
			if(total>=fujia){
				for(int i=z;i<=z+fujia-1;i++){
					printf("%c%c",yingshei_c[i],yingshei_c[i]);
				}
				printf("\n");
				for(int i=z;i<=z+fujia-1;i++){
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<2&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
				}
				jishu=z;
				huihe=2;
				return;
			}else{
				if(sum1<=5&&(dizhu==1||dizhu==2)&&huihe==1){
					for(int i=1;i<=15;i++){
						if(tot[i]==4){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
							for(int j=1;j<=sum2;j++){
								while(j<=sum2&&p2[j]==i){
									p2qipai(j);
								}
							}
							paizu=4;
							huihe=2;
							jishu=i;
							return;
						}
					}
					if(tot[14]&&tot[15]){
						sum2-=2;
						printf("XD\n");
						paizu=5;
						huihe=2;
						return;
					}
					printf("����\n");
					return;
				}else{
					printf("����\n");
					return;
				}
			}
		}
	}else if(paizu==3){					//���� 
		for(int i=jishu+1;i<=15;i++){
			if(tot[i]==3){
				if(fujia==1){			//��һ 
					for(int j=1;j<=15;j++){
						if(tot[j]==1){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j]);
							int k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<1&&o<=sum2&&p2[o]==j){
									k++;
									p2qipai(o);
								}
							}
							jishu=i;
							huihe=2;
							return;
						}
					}
					break;
				}else{					//���� 
					for(int j=1;j<=15;j++){
						if(tot[j]==2){
							printf("%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j],yingshei_c[j]);
							int k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<2&&o<=sum2&&p2[o]==j){
									k++;
									p2qipai(o);
								}
							}
							jishu=i;
							huihe=2;
							return;
						}
					}
					break;
				}
				if(sum1<=6&&(dizhu==1||dizhu==2)&&huihe==1){
					for(int i=1;i<=15;i++){
						if(tot[i]==4){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
							for(int j=1;j<=sum2;j++){
								while(j<=sum2&&p2[j]==i)
								p2qipai(j);
							}
							paizu=4;
							jishu=i;
							huihe=2;
							return;
						}
					}
					if(tot[14]&&tot[15]){
						printf("XD\n");
						sum2-=2;
						paizu=5;
						huihe=2;
						return;
					}
				}
				printf("����\n");
				return;
			}
		}
		printf("����\n");
		return;
	}else if(paizu==4){			//ը 
		if(sum1<9){
			for(int i=jishu+1;i<=15;i++){
				if(tot[i]==4){
					printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
					for(int j=1;j<=sum2;j++){
						while(p2[j]==i&&j<=sum2){
							p2qipai(j);
						}
					}
					jishu=i;
					huihe=2;
					return;
				}
			}
			if(tot[14]&&tot[15]){
				printf("XD\n");
				paizu=5;
				huihe=2;
				sum2-=2;
				return;
			}
			printf("����\n");
			return;
		}else{
			printf("����\n");
			return;
		}
	}else if(paizu==5){			//˫�� 
		printf("����\n");
		return;
	}else{						//�ɻ� 
		for(int i=jishu+1;i<15;i++){
			if(tot[i]>=3&&tot[i+1]>=3&&(tot[i]!=4||tot[i+1]!=4)){
				if(fujia==1){
					int kkk1=0,kkk2=0;
					for(int j=1;j<=15;j++){
						if(tot[j]==1){
							if(!kkk1){
								kkk1=j;
							}else{
								kkk2=j;
							}
						}else if(tot[j]==2){
							kkk1=kkk2=j;
						}
						if(kkk1&&kkk2){
							printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
							printf("%c%c\n",yingshei_c[kkk1],yingshei_c[kkk2]);
							int k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i+1){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<1&&o<=sum2&&p2[o]==kkk1){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<1&&o<=sum2&&p2[o]==kkk2){
									k++;
									p2qipai(o);
								}
							}
							jishu=i;
							huihe=2;
							return;
						}
					}
					if(sum1<=6&&(dizhu==1||dizhu==2)&&huihe==1){
						for(int i=1;i<=15;i++){
							if(tot[i]==4){
								printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
								for(int j=1;j<=sum2;j++){
									while(j<sum2&&p2[j]==i)
									p2qipai(j);
								}
								paizu=4;
								jishu=i;
								huihe=2;
								return;
							}
						}
						if(tot[14]&&tot[15]){
							printf("XD\n");
							paizu=5;
							huihe=2;
							sum2-=2;
							return;
						}
						printf("����\n");
						return;
					}
					printf("����\n");
					return;
				}else if(fujia==2){
					int kkk1=0,kkk2=0;
					for(int j=1;j<=15;j++){
						if(tot[j]==2){
							if(!kkk1){
								kkk1=j;
							}else{
								kkk2=j;
							}
						}
						if(kkk1&&kkk2){
							printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
							printf("%c%c%c%c\n",yingshei_c[kkk1],yingshei_c[kkk1],yingshei_c[kkk2],yingshei_c[kkk2]);
							int k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<3&&o<=sum2&&p2[o]==i+1){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<2&&o<=sum2&&p2[o]==kkk1){
									k++;
									p2qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum2;o++){
								while(k<2&&o<=sum2&&p2[o]==kkk2){
									k++;
									p2qipai(o);
								}
							}
							jishu=i;
							huihe=2;
							return;
						}
					}
					if(sum1<=6&&(dizhu==1||dizhu==2)&&huihe==1){
						for(int i=1;i<=15;i++){
							if(tot[i]==4){
								printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
								for(int j=1;j<=sum2;j++){
									while(j<sum2&&p2[j]==i)
									p2qipai(j);
								}
								paizu=4;
								jishu=i;
								huihe=2;
								return;
							}
						}
						if(tot[14]&&tot[15]){
							printf("XD\n");
							paizu=5;
							sum2-=2;
							huihe=2;
							return;
						}
						printf("����\n");
						return;
					}
					printf("����\n");
					return;
				}else{
					printf("%c%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					int k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i){
							k++;
							p2qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum2;j++){
						while(k<3&&j<=sum2&&p2[j]==i+1){
							k++;
							p2qipai(j);
						}
					}
					jishu=i;
					huihe=2;
					return;
				}
				break;
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]==4){
				printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
				for(int j=1;j<=sum2;j++){
					while(j<=sum2&&p2[j]==i)
					p2qipai(j);
				}
				paizu=4;
				huihe=2;
				jishu=i;
				return;
			}
		}
		if(sum1<=6&&(dizhu==1||dizhu==2)&&huihe==1){
			if(tot[14]&&tot[15]){
				printf("XD\n");
				sum2-=2;
				paizu=5;
				huihe=2;
				return;
			}
		}
	}
	printf("����\n");
	return;
}
void p3chupai(){
	printf("     p3:");
	int tot[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<=sum3;i++){
		tot[p3[i]]++;
	}
	if(paizu==0){			//���ɳ��� 
		if(sum3==2&&tot[14]&&tot[15]){
			printf("XD\n");
			sum3=0;
			return;
		}
		if(sum3==4){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						sum3=0;
						return;
					}
					break;
				}
			}
		}
		if(sum3==2){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					if(tot[i]==2){
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						sum3=0;
						return;
					}
					break;
				}
			}
		}
		if(sum3==1){
			for(int i=1;i<=15;i++){
				if(tot[i]){
					printf("%c\n",yingshei_c[i]);
					sum3=0;
					return;
				}
			}
		}
		for(int i=1;i<15;i++){
			if(tot[i]>=3&&tot[i+1]>=3&&(tot[i]!=4||tot[i+1]!=4)){
				int kkk1=0,kkk2=0,z=0;
				for(int j=1;j<=13;j++){
					if(tot[i]==1||tot[i]==2){
						if(tot[i]==z||!z){
							if(!kkk1){
								kkk1=i;
							}else{
								kkk2=i;
								break;
							}
							z=tot[i];
						}
					}
				}
				if(kkk1&&kkk2){
					printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					for(int j=1;j<=z;j++){
						printf("%c",yingshei_c[kkk1]);
					}
					for(int j=1;j<=z;j++){
						printf("%c",yingshei_c[kkk2]);
					}
					printf("\n");
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i+1){
							k++;
							p3qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum3;j++){
						while(k<z&&j<=sum3&&p3[j]==kkk1){
							k++;
							p3qipai(j);
						}
					}
					paizu=6;
					fujia=z;
					jishu=i;
					return;
				}
				kkk1=0,kkk2=0;
				for(int j=1;j<15;j++){
					if(tot[j]<=2){
						if(!kkk1){
							kkk1=j;
						}else{
							kkk2=j;
							break;
						}
					}
				}
				if(kkk1&&kkk2){
					printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					printf("%c%c\n",yingshei_c[kkk1],yingshei_c[kkk2]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i+1){
							k++;
							p3qipai(j);
						}
					}
					for(int j=1;j<=sum3;j++){
						if(p3[j]==kkk1){
							p3qipai(j);
							break;
						}
					}
					for(int j=1;j<=sum3;j++){
						if(p3[j]==kkk2){
							p3qipai(j);
							break;
						}
					}
					paizu=6;
					jishu=i;
					fujia=1;
					return;
				}
				printf("%c%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
				int k=0;
				for(int j=1;j<=sum3;j++){
					while(k<3&&j<=sum3&&p3[j]==i){
						k++;
						p3qipai(j);
					}
				}
				k=0;
				for(int j=1;j<=sum3;j++){
					while(k<3&&j<=sum3&&p3[j]==i+1){
						k++;
						p3qipai(j);
					}
				}
				paizu=6;
				fujia=0;
				jishu=i;
				return;
			}
		}
		int sum=0,total=0,z=0;
		for(int i=1;i<=15;i++){
			if(tot[i]==2){
				if(!total)
				z=i;
				total++;
			}else if(tot[i]==3){
				sum++;
				total++;
			}else{
				if(z/2>sum&&total>=3){
					for(int j=z;j<=z+total-1;j++){
						printf("%c%c",yingshei_c[j],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum3;o++){
							while(k<2&&o<=sum3&&p3[o]==j){
								k++;
								p3qipai(o);
							}
						}
					}
					printf("\n");
					paizu=2;
					fujia=total;
					jishu=z;
					return;
				}else{
					total=0;
					sum=0;
				}
			}
		} 
		for(int i=1;i<=15;i++){
			if(tot[i]==3){
				for(int j=1;j<=15;j++){
					if(tot[j]==1){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum3;o++){
							while(k<3&&o<=sum3&&p3[o]==i){
								k++;
								p3qipai(o);
							}
						}
						for(int o=1;o<=sum3;o++){
							if(p3[o]==j){
								p3qipai(o);
								break;
							}
						}
						paizu=3;
						jishu=i;
						fujia=1;
						return;
					}else if(tot[j]==2){
						printf("%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j],yingshei_c[j]);
						int k=0;
						for(int o=1;o<=sum3;o++){
							while(k<3&&o<sum3&&p3[o]==i){
								k++;
								p3qipai(o);
							}
						}
						k=0;
						for(int o=1;o<=sum3;o++){
							while(k<2&&o<=sum3&&p3[o]==j){
								k++;
								p3qipai(o);
							}
						}
						paizu=3;
						jishu=i;
						fujia=2;
						return;
					}
				}
			}
		}
		total=0,z=0;
		for(int i=1;i<=13;i++){
			if(tot[i]==1||tot[i]==2){
				if(!total)
				z=i;
				total++;
			}else{
				if(total>=5){
					for(int j=z;j<=z+total-1;j++){
						printf("%c",yingshei_c[j]);
						for(int o=1;o<=sum3;o++){
							if(p3[o]==j){
								p3qipai(o);
								break;
							}
						}
					}
					printf("\n");
					paizu=1;
					fujia=total;
					jishu=z;
					return;
				}else{
					total=0;
				}
			}
		}
		if(((dizhu==1||dizhu==3)&&(sum1==3||sum1==1))||(dizhu==3&&sum1==2)){
			for(int i=1;i<=sum3;i++){
				if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<2&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
			for(int i=1;i<=sum3;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}else if(((dizhu==1||dizhu==3)&&sum1==2)||(dizhu==3&&(sum1==3||sum1==1))){
			for(int i=1;i<=sum3;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}
			}
			for(int i=1;i<=sum3;i++){
				if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<2&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}else if(tot[i]==2){
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<2&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(k);
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]==3&&sum3==3){
				if(((dizhu==1||dizhu==2)&&sum1%2==0)){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
					paizu=1;
					fujia=1;
					jishu=i;
					return;
				}else{
					printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<2&&j<=sum3&&p3[j]==i){
							p3qipai(j);
							k++;
						}
					}
					paizu=2;
					fujia=1;
					jishu=i;
					return;
				}
			}
		}
		cout<<"BBQ3"<<endl;
		for(int i=1;i<=sum3;i++)
		printf("%c ",yingshei_c[p3[i]]);
		printf("\n");
		return;
	}else if(paizu==1){		//�����Ż�˳�� 
		if(fujia==1){		//���� 
			for(int i=jishu+1;i<=15;i++){
				if(tot[i]==1){
					printf("%c\n",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
					jishu=i;
					huihe=3;
					return;
				}
			}
			if((dizhu==1||dizhu==3)&&sum1>=5&&huihe==1){
				printf("����\n");
				return;
			}else if(sum1>2&&(dizhu==1||dizhu==3)&&huihe==1){
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==2){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							if(p3[j]==i){
								p3qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==3){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							if(p3[j]==i){
								p3qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							while(p3[j]==i&&j<=sum3){
								p3qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=3;
						return;
					}
				}
			}else if((dizhu==1||dizhu==3)&&huihe==1){
				for(int i=15;i>jishu;i--){
					if(tot[i]==2){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							if(p3[j]==i){
								p3qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				for(int i=15;i>jishu;i--){
					if(tot[i]==3){
						printf("%c\n",yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							if(p3[j]==i){
								p3qipai(j);
								break;
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				for(int i=15;i>=1;i--){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							while(p3[j]==i&&j<=sum3){
								p3qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=3;
						return;
					}
				}
			}else{
				printf("����\n");
				return;
			}
		}else{				//˳�� 
			int total=0,z=0;
			for(int i=jishu+1;i<13;i++){
				if(tot[i]&&tot[i]!=4){
					if(!total)
					z=i;
					total++;
					if(total>=fujia)
					break;
				}else{
					total=0;
				}
			}
			if(total>=fujia){
				for(int i=z;i<=z+fujia-1;i++){
					printf("%c",yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						if(p3[j]==i){
							p3qipai(j);
							break;
						}
					}
				}
				printf("\n");
				jishu=z;
				huihe=3;
				return;
			}else if(sum1<=4){
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							while(p3[j]==i&&j<=sum3){
								p3qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=3;
						return;
					}
				}
				if(tot[14]&&tot[15]){
					printf("XD\n");
					sum3-=2;
					paizu=5;
					huihe=3;
					return;
				}
			}
		}
		printf("����\n");
		return;
	}else if(paizu==2){		//���Ի����� 
		if(fujia==1){		//�� 
			if(sum1<=5&&(dizhu==1||dizhu==3)&&huihe==1){
				for(int i=15;i>jishu;i--){
					if(tot[i]>=2){
						int k=0;
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							while(k<2&&j<=sum3&&p3[j]==i){
								p3qipai(j);
								k++;
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				if(sum1<=2&&(dizhu==1||dizhu==3)&&huihe==1)
				for(int i=1;i<=15;i++){
					if(tot[i]==4){
						printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
						for(int j=1;j<=sum3;j++){
							while(j<=sum3&&p3[j]==i){
								p3qipai(j);
							}
						}
						paizu=4;
						jishu=i;
						huihe=3;
						return;
					}
				}
				printf("����\n");
				return;
			}else{
				for(int i=jishu+1;i<=15;i++){
					if(tot[i]==2){
						printf("%c%c\n",yingshei_c[i],yingshei_c[i]);
						int k=0;
						for(int j=1;j<=sum3;j++){
							while(j<=sum3&&k<2&&p3[j]==i){
								k++;
								p3qipai(j);
							}
						}
						jishu=i;
						huihe=3;
						return;
					}
				}
				printf("����\n");
				return;
			}
		}else{				//���� 
			int total=0,z=0;
			for(int i=jishu+1;i<13;i++){
				if(tot[i]>=2&&tot[i]<=3){
					if(!total)
					z=i;
					total++;
					if(total>=fujia)
					break;
				}else{
					total=0;
				}
			}
			if(total>=fujia){
				for(int i=z;i<=z+fujia-1;i++){
					printf("%c%c",yingshei_c[i],yingshei_c[i]);
				}
				printf("\n");
				for(int i=z;i<=z+fujia-1;i++){
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<2&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
				}
				jishu=z;
				huihe=3;
				return;
			}else{
				if(sum1<=5&&(dizhu==1||dizhu==3)&&huihe==1){
					for(int i=1;i<=15;i++){
						if(tot[i]==4){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
							for(int j=1;j<=sum3;j++){
								while(j<=sum3&&p3[j]==i){
									p3qipai(j);
								}
							}
							paizu=4;
							huihe=3;
							jishu=i;
							return;
						}
					}
					if(tot[14]&&tot[15]){
						sum3-=2;
						printf("XD\n");
						paizu=5;
						huihe=3;
						return;
					}
					printf("����\n");
					return;
				}else{
					printf("����\n");
					return;
				}
			}
		}
	}else if(paizu==3){					//���� 
		for(int i=jishu+1;i<=15;i++){
			if(tot[i]==3){
				if(fujia==1){			//��һ 
					for(int j=1;j<=15;j++){
						if(tot[j]==1){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j]);
							int k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<1&&o<=sum3&&p3[o]==j){
									k++;
									p3qipai(o);
								}
							}
							jishu=i;
							huihe=3;
							return;
						}
					}
					break;
				}else{					//���� 
					for(int j=1;j<=15;j++){
						if(tot[j]==2){
							printf("%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[j],yingshei_c[j]);
							int k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<2&&o<=sum3&&p3[o]==j){
									k++;
									p3qipai(o);
								}
							}
							jishu=i;
							huihe=3;
							return;
						}
					}
					break;
				}
				if(sum1<=6&&(dizhu==1||dizhu==3)&&huihe==1){
					for(int i=1;i<=15;i++){
						if(tot[i]==4){
							printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
							for(int j=1;j<=sum3;j++){
								while(j<=sum3&&p3[j]==i)
								p3qipai(j);
							}
							paizu=4;
							jishu=i;
							huihe=3;
							return;
						}
					}
					if(tot[14]&&tot[15]){
						printf("XD\n");
						paizu=5;
						sum3-=2;
						huihe=3;
						return;
					}
				}
				printf("����\n");
				return;
			}
		}
		printf("����\n");
		return;
	}else if(paizu==4){			//ը 
		if(sum1<9){
			for(int i=jishu+1;i<=15;i++){
				if(tot[i]==4){
					printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
					for(int j=1;j<=sum3;j++){
						while(p3[j]==i&&j<=sum3){
							p3qipai(j);
						}
					}
					jishu=i;
					huihe=3;
					return;
				}
			}
			if(tot[14]&&tot[15]){
				printf("XD\n");
				paizu=5;
				huihe=3;
				sum3-=2;
				return;
			}
			printf("����\n");
			return;
		}else{
			printf("����\n");
			return;
		}
	}else if(paizu==5){			//˫�� 
		printf("����\n");
		return;
	}else{						//�ɻ� 
		for(int i=jishu+1;i<15;i++){
			if(tot[i]>=3&&tot[i+1]>=3&&(tot[i]!=4||tot[i+1]!=4)){
				if(fujia==1){
					int kkk1=0,kkk2=0;
					for(int j=1;j<=15;j++){
						if(tot[j]==1){
							if(!kkk1){
								kkk1=j;
							}else{
								kkk2=j;
							}
						}else if(tot[j]==2){
							kkk1=kkk2=j;
						}
						if(kkk1&&kkk2){
							printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
							printf("%c%c\n",yingshei_c[kkk1],yingshei_c[kkk2]);
							int k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i+1){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<1&&o<=sum3&&p3[o]==kkk1){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<1&&o<=sum3&&p3[o]==kkk2){
									k++;
									p3qipai(o);
								}
							}
							jishu=i;
							huihe=3;
							return;
						}
					}
					if(sum1<=6&&(dizhu==1||dizhu==3)&&huihe==1){
						for(int i=1;i<=15;i++){
							if(tot[i]==4){
								printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
								for(int j=1;j<=sum3;j++){
									while(j<sum3&&p3[j]==i)
									p3qipai(j);
								}
								paizu=4;
								jishu=i;
								huihe=3;
								return;
							}
						}
						if(tot[14]&&tot[15]){
							printf("XD\n");
							paizu=5;
							sum3-=2;
							huihe=3;
							return;
						}
						printf("����\n");
						return;
					}
					printf("����\n");
					return;
				}else if(fujia==2){
					int kkk1=0,kkk2=0;
					for(int j=1;j<=15;j++){
						if(tot[j]==2){
							if(!kkk1){
								kkk1=j;
							}else{
								kkk2=j;
							}
						}
						if(kkk1&&kkk2){
							printf("%c%c%c%c%c%c",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
							printf("%c%c%c%c\n",yingshei_c[kkk1],yingshei_c[kkk1],yingshei_c[kkk2],yingshei_c[kkk2]);
							int k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<3&&o<=sum3&&p3[o]==i+1){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<2&&o<=sum3&&p3[o]==kkk1){
									k++;
									p3qipai(o);
								}
							}
							k=0;
							for(int o=1;o<=sum3;o++){
								while(k<2&&o<=sum3&&p3[o]==kkk2){
									k++;
									p3qipai(o);
								}
							}
							jishu=i;
							huihe=3;
							return;
						}
					}
					if(sum1<=6&&(dizhu==1||dizhu==3)&&huihe==1){
						for(int i=1;i<=15;i++){
							if(tot[i]==4){
								printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
								for(int j=1;j<=sum3;j++){
									while(j<sum3&&p3[j]==i)
									p3qipai(j);
								}
								paizu=4;
								jishu=i;
								huihe=3;
								return;
							}
						}
						if(tot[14]&&tot[15]){
							printf("XD\n");
							paizu=5;
							huihe=3;
							sum3-=2;
							return;
						}
						printf("����\n");
						return;
					}
					printf("����\n");
					return;
				}else{
					printf("%c%c%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i+1],yingshei_c[i+1],yingshei_c[i+1]);
					int k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i){
							k++;
							p3qipai(j);
						}
					}
					k=0;
					for(int j=1;j<=sum3;j++){
						while(k<3&&j<=sum3&&p3[j]==i+1){
							k++;
							p3qipai(j);
						}
					}
					jishu=i;
					huihe=3;
					return;
				}
				break;
			}
		}
		for(int i=1;i<=15;i++){
			if(tot[i]==4){
				printf("%c%c%c%c\n",yingshei_c[i],yingshei_c[i],yingshei_c[i],yingshei_c[i]);
				for(int j=1;j<=sum3;j++){
					while(j<=sum3&&p3[j]==i)
					p3qipai(j);
				}
				paizu=4;
				huihe=3;
				jishu=i;
				return;
			}
		}
		if(sum1<=6&&(dizhu==1||dizhu==3)&&huihe==1){
			if(tot[14]&&tot[15]){
				printf("XD\n");
				sum3-=2;
				paizu=5;
				huihe=3;
				return;
			}
		}
	}
	printf("����\n");
	return;
}
void p1qipai(int k){			//p1����k���� 
	for(int i=k+1;i<=sum1;i++){
		p1[i-1]=p1[i];
	}
	sum1--;
	return;
}
void p2qipai(int k){			//p2����k����
	for(int i=k+1;i<=sum2;i++){
		p2[i-1]=p2[i];
	}
	sum2--;
	return;
}
void p3qipai(int k){			//p3����k����
	for(int i=k+1;i<=sum3;i++){
		p3[i-1]=p3[i];
	}
	sum3--;
	return;
}
