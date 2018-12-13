#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

//#include "Front_Console.h"
using namespace std;


class Front_Console{
    public:

        void On_Start();///First Messages with white background
        void Key_Pass();///Method to manage password
        void Program_Accessed();/// Loading
        void Main_Screen();/// Steady main menu
        void See_List(); /// We redirect user on that page to see list
};


class Registering{ /// This class manages student registering
    public:
        void Read_Data();
        void Show_Data();
        void Write_Record();
        void Show_Record();
        void Count_Data();
    private:
        char First_Name[15];
        char Last_Name[15];
        char Sex[10];
        char Phone[15];
        char Adress[15];
        char Faculty[10];
        char BirthPlace[20];
};

void Registering::Count_Data()
{
    system("cls");
    Registering Callit;
    int n;
    ifstream infile;
    infile.open("text.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    ///cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n\n\n\t\t La liste comporte actuellement " <<count<<" ETUDIANTS, \n Vous etes sur le point d'en ajouter un(e)\n\n\n\n";
    system("pause");
    Callit.Write_Record();
}

void Generating()
{
    Sleep(200);
    system("cls");
    cout<<"\n\n\n\n\n\n \t\t  ";

  cout<<"\n\n\n\n\n\n \t\t\t\t PROCESSING \n\n\n";
    /*cout<<"\n \t\t\t\t\t PROGRAMMERS NAME: \n";
    cout<<"\n\t\t\t RICARDO PAUL - JUNIOR HERVIER -  \n";*/


    for (int j=0; j<10; j++)
    {
       cout<<"\.";
       Sleep(400);
    }
    cout<<"\n \t\t\t\t AVERAGE GENERATED !\n";
    Sleep(200);

}

class Note{
    private:
        char nom[15];
        char prenom[15];
    int co, appg, strd, ana, cpp, sys, html;
    public:
        void Note_Data(); ///write data
        void Note_Show(); /// Show data
        void Note_Write(); /// Write record to file
        void Note_Read(); /// Read record from file
};

void Note::Note_Data(){
    cout<<"\t\tNom De L'Etudiant :";
    cin>>nom;
    cout<<"\t\t Prenom De L'Etudiant\n :";
    cin>>prenom;
    cout<<prenom<<"  VEUILLEZ ENTRER VOS NOTES -->(note/100)";
    cout<<"Concept Objet :";
    cin>>co;
    cout<<"Application Graphique :";
    cin>>appg;
    cout<<"Structure de donnee :";
    cin>>strd;
    cout<<"Analyse Numerique :";
    cin>>ana;
    cout<<"C++ :";
    cin>>cpp;
    cout<<"Systeme d'exploitation:";
    cin>>sys;
    cout<<"HTML5 / CSS3 :";
    cin>>html;

    ///Data Processing

    Front_Console Back; ///Object for class font console
    Generating();

	Sleep(200);
    system("CLS");
    system("color 2F");
    int Sum = co+ appg + strd + ana + cpp + sys + html;
    int Average = Sum /7;
    cout<<"\n\n\n\n\n\n\n\n\n\t\tVotre Moyenne est "<<Average<<endl;

    	if(Average<60)
	{
		cout<<" \n\n A REFAIRE LA CLASSE / STUDENT FAILED";
	}
	if(Average>=70)
	{
		cout<<" \n\n\n ADMIS / CONGRATULATIONS on your Success !!! \n";
	}
	if(Average>=60 && Average<70)
	{
		cout<<" \n\n\n ETUDIANT AJOURNE / ";
	}

    system("pause");
    Back.Main_Screen();

}

void Note::Note_Write(){
ofstream f("mynotes.txt" , ios::binary | ios:: app);
if (!f)
{
    cout<<"error";
}
Note_Data();
f.write( reinterpret_cast <char*> (this) , sizeof(*this));
f.close();
}


void Note::Note_Show(){
cout<<"------------------------------------------";
  cout<<"Nom :"<<nom<<endl;
    ///cin>>nom;
    cout<<"Prenom :"<<prenom<<endl;
   /// cin>>prenom;
    cout<<"CO :"<<co<<endl;
    ///cin>>co;
    cout<<"Application Graphique :"<<appg<<endl;
    ///cin>>appg;
    cout<<"Structure de donnee :"<<strd<<endl;
    ///cin>>strd;
    cout<<"Analyse Numerique :"<<ana<<endl;
    ///cin>>ana;
    cout<<"C++ :"<<cpp<<endl;
   /// cin>>cpp;
    cout<<"Systeme d'exploitation:"<<sys<<endl;
   /// cin>>sys;
    cout<<"HTML5 / CSS3 :"<<html<<endl;
   /// cin>>html;
   cout<<"----------------------------------------";
   cout<<"\n\n";

}

void Note::Note_Read()
{
    ifstream g("mynotes.txt" , ios::binary);
    if(!g)
    {
        cout<<"\n\n\t Failed to open file";
    }
    while(!g.eof())
    {
        if(  g.read( reinterpret_cast <char*> (this) , sizeof(*this) ) >0 )
        {
            Note_Show();
        }
    }
    g.close();

    Front_Console Back;
    system("pause");
    Back.Main_Screen();

}

void Note_Generator()
{
    ///An object for front console so that we can back to the main screen
    Front_Console Back;
    int co, appg, strd, ana, cpp, sys, html;

    cout<<"\n\n    COURS DE PROGRAMMATION    "<<endl;
    cout<<"**** ENTRER VOS NOTES ****"<<endl;
	cout<<"\t \nJAVASCRIPT      :";
	cin>>co;
	cout<<"\t \nC++             :";
	cin>>appg;
	cout<<"\t \nBOOTSTRAP       :";
	cin>>strd;
	cout<<"\t \nPYTHON          :";
	cin>>ana;
	cout<<"\t \nRUBY            :";
	cin>>cpp;
	cout<<"\t \nSWIFT           :";
	cin>>sys;
	cout<<"\t \nHTML/CSS        :";
	cin>>html;
	Generating();

	Sleep(200);
    system("CLS");
    system("color 2F");
    int Sum = co+ appg + strd + ana + cpp + sys + html;
    int Average = Sum /7;
    cout<<"\n\n\n\n\n\n\n\n\n\t\tVotre Moyenne est "<<Average<<endl;
    system("pause");
    Back.Main_Screen();


}

/// By this method we give access to database just pressing any key. press any key again and we get user back to main(optio) screen
void Front_Console::See_List()
{
    Front_Console Return_Instance;
    Registering DataBase;
    Sleep(300);
    system("cls");
    system("color 2F");
    ///cout<<"\t\t View OUR DataBase";
    cout<<"\n\n\n\n\n\n \t\t STUDENT'S INFORMATION WERE SUCCESSFULLY SAVED ON OUR SYSTEM  \n\n";
        cout<<"\n\n\n\n\n\n \t\t\t SEE OUR DATABASE ... ... ...  \n\n";
    system("pause");
    DataBase.Show_Record();
    system("pause");
    Return_Instance.Main_Screen();



}

void Registering::Show_Data()
{
    ///system("cls");
  cout<<"_________________________________________";
      cout<<" \n\n\n \t\t";
  cout<<" 1. Nom De L'Etudiant: "<<Last_Name<<endl;
  ///cin>> Last_Name;
  cout<<" \n \t\t";
  cout<<" 2. Prenom De L'Etudiant: "<<First_Name<<endl;
  ///cin>> First_Name;
 cout<<" \n \t\t";
  cout<<" 3. Sexe: "<<Sex<<endl;
  ///cin>> Sex;
  cout<<" \n \t\t";
  cout<<" 4. Telephone: "<<Phone<<endl;
  ///cin>> Phone;
  cout<<" \n \t\t";
  cout<<" 5. Adresse: "<<Adress<<endl;
  ///cin>>Adress;
  cout<<" \n \t\t";
  cout<<" 6. Lieu de Naissance: "<<BirthPlace<<endl;
  ///cin>> BirthPlace;
  cout<<" \n \t\t";
  cout<<" 7. Faculte Choisie: "<<Faculty<<endl;
  ///cin>>Faculty;
   cout<<"_________________________________________";
}

void Registering::Show_Record()
{
    Front_Console GoBack;
    ifstream infile("text.txt", ios::binary);
    if (!infile)
    {
        cout<<"Failed while Opening file";
    }
    cout<<"\t\t ***Data From File***";
    while(!infile.eof())
    {
        if( infile.read(reinterpret_cast <char*> (this), sizeof(*this))>0 )
        {
            Show_Data();
        }
    }
      infile.close();
      system("pause");
      GoBack.Main_Screen();

}

void Registering::Read_Data()
{
    Sleep(1000);
    system("cls");
    ///We create an object for class Font_Console to call its method See_List
    ///Because we want to get back to this method where we give link to see OUR Database
    Front_Console Object2;


  cout<<" \n\n\n \t\t";
  cout<<" 1. Nom De L'Etudiant      : ";
  cin>> Last_Name;
  cout<<" \n \t\t";
  cout<<" 2. Prenom De L'Etudiant   : ";
  cin>> First_Name;
 cout<<" \n \t\t";
  cout<<" 3. Sexe                   : ";
  cin>> Sex;
  cout<<" \n \t\t";
  cout<<" 4. Telephone              : ";
  cin>> Phone;
  cout<<" \n \t\t";
  cout<<" 5. Adresse                : ";
  cin>>Adress;
  cout<<" \n \t\t";
  cout<<" 6. Lieu de Naissance      : ";
  cin>> BirthPlace;
  cout<<" \n \t\t";
  cout<<" 7. Faculte Choisie        : ";
  cin>>Faculty;
  Sleep(2000);

  ///Show_Record();
  ///system("pause");




  /*cout<<"\t\t"<<First_Name<<endl;
  cout<<" Nous vous souhaitons la bienvenue, veuillez lire nos reglements: \n\n";
  cout<<"\n \t\t ----> PLEASE MOVE FORWARD TO READ OUR CONDITIONS \n\n\n\n\n";
  system("pause");
  ///Here we get the user back to the main screen, using the object we have created

    ///Object2.Main_Screen(); */
}

void Registering::Write_Record()
{
    Front_Console Check;
    ofstream outfile ("text.txt", ios::binary | ios::app);
    Read_Data();
    outfile.write(reinterpret_cast<char*>( this), sizeof(*this) );
    outfile.close();
    ///Show_Record();


     system("cls");
  cout<<"\n\n\n\n\n\n \t\t  ";

  cout<<"\n\n\n\n\n\n \t\t PLEASE WAIT WHILE STUDENT IS BEING REGISTERED ON OUR SYSTEM  \n\n\n";
    /*cout<<"\n \t\t\t\t\t PROGRAMMERS NAME: \n";
    cout<<"\n\t\t\t RICARDO PAUL - JUNIOR HERVIER -  \n";*/


  for (int j=0; j<80; j++)
    {
       cout<<"\xB2";
       Sleep(100);
    }
    cout<<"\n \t\t\t REGISTRATION COMPLETED ! \n";
    Sleep(3000);
    system("cls");
    cout<<"\n\n\n\n";
    ///Object2.See_List();
    Check.See_List();
}

void Front_Console::Main_Screen()
{
   Sleep(1000);
   system("cls");
   system("color 0F");
   ///cout<<"\n\n\n\n\n\n\n\n\n\n \t\t\t\t Password: ";
  cout<<"\n\n\n";
  cout<<"\t\t\t  ------------------------------------------\n";
  cout<<"\t\t\t  |SYSTEME D'INSCRIPTION / CALCUL DE MOYENNE|\n";
  cout<<"\t\t\t  ------------------------------------------\n";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<" 1. Inscire Un Etudiant \n\n";
  cout<<"\t\t\t\t";
  cout<<" 2. Voir les Etudiants Inscrits (DATA BASE) \n\n";
  cout<<"\t\t\t\t";
  cout<<" 3. Faire un calcul de moyenne \n\n";
  cout<<"\t\t\t\t";
  cout<<" 4. Moyennes deja Calculees (DATA BASE) \n\n\n\n";
  ///cout<<"\t";
  cout<<" Each Option Will Redirect You To This Screen As You Navigate Through."<<endl;
  cout<<"\t";
  cout<<" Please Press (key) 5 if you want to exit the program \n\n";
  cout<<"Choose options:    ";


  int choice;
  cin>>choice;

  switch(choice)
  {
      Note mn; ///Object created for note class
      /// We create an object for our class Registering in order to call its method Write_Record
      Registering Object;
  case 1:
      Object.Count_Data();
    ///Object.Write_Record();
  case 2:
    Object.Show_Record();
  case 3: mn.Note_Write();

  case 4:mn.Note_Read();
  case 5:exit(0);

  }

}


void Front_Console::Program_Accessed()
{
    system("color 0F");
    cout<<"\n\n\n\n\n\n \t\t PLEASE WAIT WHILE PROGRAM'S COMPONENTS ARE LOADING \n\n\n";
    cout<<"\n \t\t YOU'LL BE AUTOMATICALLY REDIRECTED TO THE MAIN MENU  \n";
    cout<<"\n\t\t\t\t ONCE LOADING IS DONE \n";
    for (int j=0; j<80; j++)
    {
       cout<<"\xdb";
       Sleep(300);
    }
    cout<<"\n \t\t\t\t\t LOADED! \n";
    Main_Screen();


}

void Front_Console::Key_Pass()
{
    system("cls");
    system("color 4F");
    char Get_Pass[12];
    start:
    cout<<"\n\n\n\n\n\n\n\n\n\n \t\t\t\t Password: ";
    for (int i=0; i<11; i++)
    {
        Get_Pass [11]='\0';
        Get_Pass[i]=getch();
        cout<<"*";

    }
    if(strcmp(Get_Pass, "corporation")==0)
    {
        for (int i=0; i<1; i++)
        {
            cout<<"\n\n \t\t\t\t ACCESS GRANTED !!!";
            ///system("cls");
            Sleep(2000);
        }

        Sleep(3000);
        system("cls");

        Program_Accessed();
    }
    else{
            cout<<"Exit";
    }
}

void type() ///Woord By Word Into
{
    ///string content, double 200
    ///int time=200;
    system("color 1F");
string content ="\n\n\n\n\t\t CE PROGRAMME EST LE RESULTAT D'UNE CONTRIBUTION ACTIVE \n\t\t\t ET ASSIDUE DES INGENIEURS : ";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(110);
}
}

void Rach() /// Introducing Rachelle
{
    ///string content, double 200
    ///int time=200;
string content ="\n\n\t\t\t\t LAVILETTE Rachelle";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(80);
}
}

void Herv()
{
    ///string content, double 200
    ///int time=200;
string content ="\n\n\t\t\t\t HERVIER Junior";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(80);
}
}

void Yven()
{
    ///string content, double 200
    ///int time=200;
string content ="\n\n\t\t\t\t FENELON Yvenson";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(80);
}
}

void Ricky()
{
    ///string content, double 200
    ///int time=200;
string content ="\n\n\t\t\t\t et PAUL Ricardo\n\n\n\n";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(80);
}
}

void Text_Last()
{
    ///string content, double 200
    ///int time=200;
    system("cls");
string content ="\n\n\t\t Ce Programme cree un support dans sa location sur \n\t\t le disque dur lui servant de base de donnee, ou sont \n\t\t stockees et classees  toutes les informations collectees \n\t\t sur les etudiants allant des inscriptions aux calculs \n\t\t de moyennes. \n\n\t\tBuilt To Support An Unlimited Amount Of Students\n\n\n";
int length = content.length();
///Sleep(200);
for(int i = 0; i<length;i++)
{
char a = content[i];
cout << a;
Sleep(40);
}
}

void Front_Console::On_Start()
{
    system("color ");
    Sleep(1000);
    cout<<"\n\n\n\n\t\t *************************************************";
    cout << "\n Nous avons concu ce programme pour faire des inscriptions et des calculs \n \t\t de moyennes pouvant -- aller jusqu'a N etudiants \n\t\t\t " << endl;
    cout << "\n\n \tWE CREATE A SUPPORT IN THE PROGRAM LOCATION IN THE COMPUTER\n \t WHERE WE SAVE ALL COLLECTED DATA DURING REGISTRATION PROCESS \n\n\n\n\n\n\n\n\n \t\t " << endl;
    system("pause");
    //Sleep(9000);
    system("cls");
    Sleep(700);
    type();
    Sleep(100);
    Rach();
    Sleep(100);
    Herv();
    Sleep(100);
    Yven();
    Sleep(100);
    Ricky();
    system("pause");
    Text_Last();
    //cout << "\n\n\n\n\n\n\n\n\nNB: NOUS FOURNISSONS L'ACCES AU PROGRAMME EXCLUSIVEMENT AUX ADMINISTRATEURS\n \t\t " << endl;
    ///cout << "\n\n\n\n\n\n\n\n\n   NB: nous avons conserve l'acces au programme seulement a un administrateur\n\n\n\n \t\t " << endl;
    ///MessageBox ( 0 , " the driver is sleeping , nous fournissons l'acces au programme qu'aux administrateurs" , "RICKY MESSAGE" ,0 );
    system("pause");
    Key_Pass();
}

int main()
{
    Front_Console Access;
    //Access.On_Start();

    ///Registering Object;
    ///Object.Write_Record();
    ///Object.Show_Record();
    Access.On_Start();
    ///Access.Main_Screen();
    //Registering Call;
    //Call.Write_Record();

    return 0;
}
