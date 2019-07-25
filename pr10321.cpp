//AM:10321,EIRINI ELEUTHERIOU
#include <iostream>
#include <cstdlib>
using namespace std;
bool sunadisi1oueidous(int g1,int s1,int g2,int s2,int M,int N);
//Elegxei an to ena robot borei na dei to allo katheta,orizodia i diagwnia
void sunadisi2oueidous(int g1,int s1,int g2,int s2,int E[][2],int r1[][40],int r2[][40],int& u);
//Elegxei an to ena robot paei se thesi apo tin opoia exei perasei to allo robot
void sunadisi3oueidous(int& g1,int& s1,int& g2,int& s2,int S[][2],int C[][2],int M,int N );
//Elegxei an kapoio apo ta robot epixeirei na paei sti thesi pou vrisketai to allo
void epitrgrammes(int& g,int M);
//Dinei ti nea grammi stin opoia tha paei to robot analoga me tin thesi tou ston pinaka
void epitrstiles(int& s,int N);
//Dinei ti nea stili stin opoia tha paei to robot analoga me tin thesi tou ston pinaka
int main()
{
	char response;
	int x1,y1,x2,y2,M,N,K,T,u,p;
	const int MAXM=40;
	const int MAXN=40;
	int r1[40][40],r2[40][40],S[1][2],E[1][2],C[1][2];
	cout<<"Dwste tin thesi tou 1ou robot,grammi kai stili"<<endl;
	cin>>x1>>y1;
	cout<<"Dwste tin thesi tou 2ou robot,grammi kai stili"<<endl;
	cin>>x2>>y2;
	cout<<"Dwste to megethos tou pinaka,grammes kai stiles"<<endl;
	cin>>M>>N;
	cout<<"Dwste ton arithmo twn vimatwn(K) gia ton opoio tha kanoume to peirama"<<endl;
	cin>>K;
	cout<<"Dwste ton arithmo twn vimatwn(T) gia ton opoio tha paramenei energo to ixnos"<<endl;
	cin>>T;
	//p=to plithos twn peiramatwn pou tha pragmatopoihthoun
	p=0;
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<2;j++)
		{
			S[i][j]=0;
			E[i][j]=0;
			C[i][j]=0;
		}
	}
	/*Dimiourgoume 2 pinakes tous opoious arxika midenizoume kai epeita apothikeuoume ton arithmo 1 sta kelia tou 1ou pinaka apo ta opoia perase to 1o robot.To
	idio kanoume kai ston 2o pinaka gia to 2o robot.Etsi ta mi midenika kelia tou kathe pinaka einai to ixnos tou adistoixou robot*/
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			r1[i][j]=0;
			r2[i][j]=0;
		}
	}
	r1[x1][y1]=1;
	r2[x2][y2]=1;
	//u=to plithos twn vimatwn pou ekanan ta robot,to apothikeumeno ixnos
	u=1;
	do
	{
		p++;
		for(int i=0;i<K;i++)
		{
			sunadisi3oueidous(x1,y1,x2,y2,S,C,M,N);
			/*Prin kalesoume tin sunartisi pou apothikeuei ta ixnh twn robot elegxoume an ta robot ekanan T vimata wste ta uparxoda ixnh na diagrafoun kai na 
			apothikeutoun ta nea */
			if(u==T)
			{
				cout<<"Ta robot ekanan T vimata"<<endl;
				for(int i=0;i<M;i++)
				{
					for(int j=0;j<N;j++)
					{
						r1[i][j]=0;
						r2[i][j]=0;
					}
				}
				u=1;
				continue;
				/*Midenisame tous pinakes,apothikeusame ya ixnh kai den elegxoume an to ena robot paei se keli pou exei perasei to allo robot dioti exoume mono
				mia thesi apothikeumeni,opote prospername tin sunartisi pou afora to ixnos*/
			}
			else
			{
				cout<<"Ta robot den ekanan akoma T vimata"<<endl;
				sunadisi2oueidous(x1,y1,x2,y2,E,r1,r2,u);
			}
			
		}
		cout<<"Gia to "<<p<<"o peirama exoume ta exhs:"<<endl;
		cout<<"To 1o robot borese na dei "<< S[0][0] <<" fores to 2o robot"<<endl;
		cout<<"To 2o robot borese na dei "<< S[0][1] <<" fores to 1o robot"<<endl;
		cout<<"To 1o robot perase apo "<< E[0][0] <<" kelia opou upirxe ixnos tou 2ou"<<endl;
		cout<<"To 2o robot perase apo "<< E[0][1]<<" kelia opou upirxe ixnos tou 1ou"<<endl;
		cout<<"To 1o robot epixeirhse "<< C[0][0] <<" fores na paei se thesi opou upirxe hdh to 2o robot"<<endl;
		cout<<"To 2o robot epixeirhse "<< C[0][1]<<" fores na paei se thesi opou upirxe hdh to 2o robot"<<endl;
		cout<<"Thes na sunexiseis me to epomeno peirama(y/n):"<<endl;
		cin>>response;
	}
	while((response=='y')|| (response=='Y'));
	system ("PAUSE");
	return 0;
}


bool sunadisi1oueidous(int g1,int s1,int g2,int s2,int M,int N)
{
	int l,t,i,j;
	bool sun1;
	sun1=false;
	//Thetoume sta l kai t ti thesi tou 1ou robot kai ellatwnoume mexri na ftasoume sta oria tou pinaka kai vroume to 1o stoixeio tis diagwniou
	l=g1;
	t=s1;
	while(l>0 && t>0)
	{
		l--;
		t--;
	}
	/*Arxizoume tin anazitisi stin 1h diagwnio thetontas se kathe deikti tin thesi tou 1ou stoixeiou kai stamata otan ftasoume sta oria h otan snadithoun ta
	robot*/
	i=l;
	j=t;
	//An sunadithoun h anazitisi stamata diaforetika sunexizoume me tin epomeni thesi
	while(i<M && j<N && sun1==false)
	{
		if(i==g2 && j==s2)
		{
			sun1=true;
		}
		else
		{
			i++;
			j++;
		}
	}
	//An den vrisketai stin 1h diagwnio elegxoume tin 2h me ton idio tropo
	if(sun1==false)
	{
		l=g1;
		t=s1;
		while(l>0 && t<N-1)
		{
			l--;
			t++;
		}
		i=l;
		j=t;
		while(i<M-1 && j>0 && sun1==false)
		{
			if(i==g2 && j==s2)
			{
				sun1=true;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	//An den vrisketai se kamia diagwnio psaxnoume th grammi 
	if(sun1==false)
	{
		for(int j=0;j<N;j++)
		{
			if(g1==g2 && s2==j)
			{
				sun1==true;
			}
		}
	}
	//An den vrisketai oute stin grammi psaxnoume tin stili 
	if(sun1==false)
	{
		for(int i=0;i<M;i++)
		{
			if(s1==s2 && g2==i)
			{
				sun1=true;
			}
		}
	}
	return(sun1);	
}


void sunadisi2oueidous(int g1,int s1,int g2,int s2,int E[][2],int r1[][40],int r2[][40],int& u)
{
	/*Gia ti nea thesi tou 1ou robot elegxoume an to keli tou 2ou pinaka me auti ti thesi exei mi mideniko stoixeio,ara to 2o robot exei perasei apo auto to keli
	prohgoumenws kai o metritis E auxanetai*/
	if(r2[g1][s1]!=0)
	{
		E[0][0]++;
	}
	//Kanoume to idio gia to 2o robot
	if(r1[g2][s2]!=0)
	{
		E[0][1]++;
	}
	//Efoson ta robot metakinithikan apothikeuoume ta neo ixnos tou kathenos
	r1[g1][s1]=1;
	r2[g2][s2]=1;
	u++;
}

void sunadisi3oueidous(int& g1,int& s1,int& g2,int& s2,int S[][2],int C[][2],int M,int N)
{
	int g,s;
	bool sun1;
	sun1=false;
	sun1=sunadisi1oueidous(g1,s1,g2,s2,M,N);
	if(sun1==true)
	{
		S[0][0]++;
		cout<<"To 1o robot borei na dei to allo"<<endl;
	}
	else
	{
		cout<<"To 1o robot den borei na dei to allo"<<endl;
	}
	/*Apothikeuoume ti thesi tou 1ou robot stis metavlites g kai s kai elegxoume an i epomeni thesi tou einai idia me ti thesi tou 2ou,an nai paramenei stin 
	prohgoumeni thesi kai auxanetai o metritis C*/
	g=g1;
	s=s1;
	//Dinetai i nea tuxaia thesi tou 1ou robot analoga me tin thesi tou ston pinaka i opoia den borei na einai i idia me prin
	do
	{
		epitrgrammes(g1,M);
		epitrstiles(s1,N);
	}
	while(g==g1 && s==s1);
	//Elegxoume an to 1o robot epixeirei na paei sti thesi tou 2ou,se auti mono tin periptwsi to robot paramenei stin idia thesi
	if(g1==g2 && s1==s2)
	{
		g1=g;
		s1=s;
		C[0][0]++;
		cout<<"To 1o robot epixeirise na paei sti thesi tou 2ou gi' auto paremeine stin idia thesi"<<endl;
	}
	cout<<"To 1o robot vrisketai sti thesi ("<<g1<<","<<s1<<")"<<endl;
	sun1=false;
	sun1=sunadisi1oueidous(g1,s1,g2,s2,M,N);
	if(sun1=true)
	{
		S[0][1]++;
		cout<<"To 2o robot borei na dei to allo"<<endl;
	}
	else
	{
		cout<<"To 2o robot den borei na dei to allo"<<endl;
	}
	g=g2;
	s=s2;
	//Dinetai i tuxaia thesi tou 2ou robot
	do
	{
		epitrgrammes(g2,M);
		epitrstiles(s2,N);
	}
	while(g==g2 && s==s2);
	//Akolouthoume ti idia diadikasia gia tin kinisi tou 2ou robot
	if(g1==g2 && s1==s2)
	{
		g2=g;
		s2=s;
		C[0][1]++;
		cout<<"To 2o robot epixeirise na paei sti thesi tou 1ou gi' auto paremeine stin idia thesi"<<endl;
	}
		cout<<"To 2o robot vrisketai sti thesi ("<<g2<<","<<s2<<")"<<endl;
}

void epitrgrammes(int& g,int M)
{
	if(g==0)
	{
		//An vrisketai stin 1h grammi paramenei stin idia eite paei stin apo katw
		g=rand() % 2;
	}
	else if(g==M-1)
	{
		//An einai stin teletaia paramenei se auti h paei stin apo katw
		g=rand() % 2+(M-2);
	}
	else
	{
		//Se alli periptwsi paramenei pali stin idia h paei stin akrivws apo panw h apo katw
		g=rand() % 3+(g-1);
	}	
}

void epitrstiles(int& s,int N)
{
	if(s==0)
	{
		s=rand() % 2;
	}
	else if(s==N-1)
	{
		s=rand() % 2+(N-2);
	}
	else
	{
		s=rand() % 3+(s-1);
	}
}

















