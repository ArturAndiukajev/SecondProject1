#include "firstlib.h"

int main()
{
    int stud_sk=0;
    vector <Studentas> studentai;
    Studentas naujas_st;
    vector <Studentas> vargsiukai;
    Studentas vargsiukas;
    vector <Studentas> kietiakiai;
    Studentas kietiakis;
    cout<<"Ar norite sugeneruoti faila? Jeigu taip - rasykite 'T', jeigu ne - 'N'."<<endl;
    char pasirinkimas5;
    cin>>pasirinkimas5;
    if(pasirinkimas5=='T'||pasirinkimas5=='t')
    {
        cout<<"Iveskite studentu skaiciu"<<endl;
        int studentu_sk;
        cin>>studentu_sk;
        cout<<"Iveskite failo pavadinima"<<endl;
        string failoPav;
        cin>>failoPav;
        cout<<"Iveskite namu darbu kieki"<<endl;
        int namuDarbu_kiekis;
        cin>>namuDarbu_kiekis;
        generavimas(studentu_sk,failoPav,namuDarbu_kiekis);
        cout<<"Ar norite baigti darba? Jeigu taip - rasykite 'T', jeigu ne - 'N'."<<endl;
        char pasirinkimas7;
        cin>>pasirinkimas7;
        if(pasirinkimas7=='T'||pasirinkimas7=='t')
        {
            return 1;
        }
    }
    cout<<"Ar norite testuoti skaitymo, rusiavimo ir isvedimo laika? Jeigu taip - rasykite 'T', jeigu ne - 'N'."<<endl;
    char pasirinkimas8;
    cin>>pasirinkimas8;
    if(pasirinkimas8=='T'||pasirinkimas8=='t')
    {
        cout<<"Iveskite failo pavadinima."<<endl;
        string failoPav;
        cin>>failoPav;
        cout<<"Kiek kartu norite perskaityti faila ir surusiuoti?"<<endl;
        int skaitk;
        cin>>skaitk;
        double riba=5.0;
        cout<<"Pasirinkite buda, kaip surusioti rezultatus. Jeigu norite rusiuoti pagal varda, rasykite 'V', jeigu pagal pavarde - 'P', pagal vidurki 'A'"<<endl;
        char pasirinkimas9;
        cin>>pasirinkimas9;
        for(int i=0;i<skaitk;i++)
        {
            vargsiukai.clear();
            kietiakiai.clear();
            skaitymas(studentai,failoPav);
            auto pradzia=std::chrono::high_resolution_clock::now();
            for(int i=0;i<studentai.size();i++)
            {
                if(studentai[i].galutinis1<riba)
                {
                    vargsiukai.push_back(studentai[i]);
                }
                else
                {
                    kietiakiai.push_back(studentai[i]);
                }
            }
            auto pabaiga=std::chrono::high_resolution_clock::now();
            auto uztruko=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);
            cout<<"Rusiavimo i grupes laikas:"<<uztruko.count()<<" milisekundziu"<<endl;
            if(pasirinkimas9=='V'||pasirinkimas9=='v')
            {
                auto pradzia2=std::chrono::high_resolution_clock::now();
                sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVardai);
                auto pabaiga2=std::chrono::high_resolution_clock::now();
                auto uztruko2=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                auto pradzia3=std::chrono::high_resolution_clock::now();
                sort(kietiakiai.begin(), kietiakiai.end(), palyginimasVardai);
                auto pabaiga3=std::chrono::high_resolution_clock::now();
                auto uztruko3=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                cout<<"Vargsiuku rusiavimas pagal varda uztruko "<<uztruko2.count()<<" milisekundziu"<<endl;
                cout<<"Kietiaku rusiavimas pagal varda uztruko "<<uztruko3.count()<<" milisekundziu"<<endl;
            }
            else if(pasirinkimas9=='P'||pasirinkimas9=='p')
            {
                auto pradzia2=std::chrono::high_resolution_clock::now();
                sort(vargsiukai.begin(), vargsiukai.end(), palyginimasPavardes);
                auto pabaiga2=std::chrono::high_resolution_clock::now();
                auto uztruko2=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                auto pradzia3=std::chrono::high_resolution_clock::now();
                sort(kietiakiai.begin(), kietiakiai.end(), palyginimasPavardes);
                auto pabaiga3=std::chrono::high_resolution_clock::now();
                auto uztruko3=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                cout<<"Vargsiuku rusiavimas pagal pavarde uztruko "<<uztruko2.count()<<" milisekundziu"<<endl;
                cout<<"Kietiaku rusiavimas pagal pavarde uztruko "<<uztruko3.count()<<" milisekundziu"<<endl;
            }
            else if(pasirinkimas9=='A'||pasirinkimas9=='a')
            {
                auto pradzia2=std::chrono::high_resolution_clock::now();
                sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVidurkis);
                auto pabaiga2=std::chrono::high_resolution_clock::now();
                auto uztruko2=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                auto pradzia3=std::chrono::high_resolution_clock::now();
                sort(kietiakiai.begin(), kietiakiai.end(), palyginimasVidurkis);
                auto pabaiga3=std::chrono::high_resolution_clock::now();
                auto uztruko3=std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                cout<<"Vargsiuku rusiavimas pagal pavarde vidurki "<<uztruko2.count()<<" milisekundziu"<<endl;
                cout<<"Kietiaku rusiavimas pagal pavarde vidurki "<<uztruko3.count()<<" milisekundziu"<<endl;
            }
            else
            {
                cout<<"Netinkamas pasirinkimas"<<endl;
                return 1;
            }
            isvedimas(vargsiukai, "vargsiukai.txt");
            isvedimas(kietiakiai, "kietiakiai.txt");
            cout<<"---------------------------------------------------------------------------"<<endl;
        }
            cout<<"Ar norite pabaigti darba? Jeigu taip rasykite 'T', jeigu ne - 'N'"<<endl;
            char pasirinkimas6;
            cin>>pasirinkimas6;
            if(pasirinkimas6=='T'||pasirinkimas6=='t')
            {
                return 1;
            }
    }
    cout<<"Pasirinkite buda, kaip pildysite duomenys. Jeigu norit ivesti patys rasykite 'P', jeigu norite nuskaityti is failo - 'F'"<<endl;
    char pasirinkimas3;
    cin>>pasirinkimas3;
    if(pasirinkimas3=='P'||pasirinkimas3=='p')
    {
        cout<<"Iveskite studentu kieki: "<<endl;
        cin>>stud_sk;
        if(stud_sk<=0)
        {
            cerr<<"Studentu skaicius turi buti didesnis uz 0."<<endl;
            return 1;
        }
        cout<<"Pasirinkite buda, kaip pildysite namu darbo pazimius. Jeigu norit ivesti patys rasykite 'A', jeigu atsitiktinai - rasykite 'R'"<<endl;
        char pasirinkimas2;
        cin>>pasirinkimas2;
    //------------------------------------------------Duomenu ivedimas----------------------------------------------------------------------------------
        for(int i=0;i<stud_sk;i++)
        {
            cout<<"Iveskite "<<i+1<<" studento varda"<<endl;
            cin>>naujas_st.vardas;
            cout<<"Iveskite "<<i+1<<" studento pavarde"<<endl;
            cin>>naujas_st.pavarde;
            if (pasirinkimas2=='A'||pasirinkimas2=='a')
            {
                cout<<"Iveskite "<<i+1<<" studento namu darbo rezultatus (iveskite '-1', kai baigsite)"<<endl;
                int nd_rez;
                while (true)
                {
                    if (cin >> nd_rez)
                    {
                        if (nd_rez == -1)
                        {
                            break;
                        }
                        else if(nd_rez>10 || nd_rez<0)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Pazymys negali buti didesnis uz 10 arba mazesnis uz 0"<<endl;
                        }
                        else
                        {
                            naujas_st.ND.push_back(nd_rez);
                        }
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Tai ne skaicius." << endl;
                    }
                }}
            else if(pasirinkimas2=='R'||pasirinkimas2=='r')
            {
                int nd_kiekis;
                cout<<"iveskite kiek namu darbu rezultatu noresite sugeneruoti"<<endl;
                cin>>nd_kiekis;
                if(nd_kiekis<=0)
                {
                    cout<<"Iveskite skaiciu didesni uz 0."<<endl;
                    return 1;
                }
                cout<<"Sugeneruoti namu darbu rezultatai:"<<endl;
                for(int i=0;i<nd_kiekis;i++)
                {
                    int nd_rez;
                    nd_rez=rand()%10+1;
                    cout<<nd_rez<<endl;
                    naujas_st.ND.push_back(nd_rez);
                }
            }
            else
            {
                cout<<"Neteisingas pasirinkimas";
                return 1;
            }
            if (pasirinkimas2=='A'||pasirinkimas2=='a')
            {
                cout<<"Iveskite "<<i+1<<" studento egzamino rezultata"<<endl;
                cin>>naujas_st.Egz;
                if(!cin>>naujas_st.Egz)
                {
                    cout<<"Iveskite skaiciu."<<endl;
                    return 1;
                }
                else if(naujas_st.Egz<=0 || naujas_st.Egz>10)
                {
                    cout<<"Iveskite skaiciu didesni uz 0 ir mazesni uz 10."<<endl;
                    return 1;
                }
            }
            else if(pasirinkimas2=='R'||pasirinkimas2=='r')
            {
                naujas_st.Egz=rand()%10+1;
                cout<<"Sugeneruotas Egzamino rezultatas"<<" "<<naujas_st.Egz<<endl;
            }
            else
            {
                cout<<"Neteisingas pasirinkimas";
                return 1;
            }
        double nd_suma = accumulate(naujas_st.ND.begin(), naujas_st.ND.end(), 0.0);
        naujas_st.galutinis1=rezultatas(nd_suma, naujas_st.ND.size(), naujas_st.Egz);
        double mediana=Med(naujas_st.ND);
        naujas_st.galutinis2=rezMed(mediana,naujas_st.Egz);
        studentai.push_back(naujas_st);
        }}
    else if(pasirinkimas3=='F'||pasirinkimas3=='f')
    {
        string Fname;
        cout<<"Iveskite failo pavadinima su '.txt'"<<endl;
        cin>>Fname;
        ifstream input_file(Fname);
        if (!input_file.is_open())
        {
            cout << "Failo atidarymas negalimas: " << Fname << endl;
            return 1;
        }
        string header;
        int stulp_kiekis=0;
        getline(input_file, header);
        string v;
        string p;
        std::istringstream headerStream(header);
        string token;
        while (headerStream >> token)
        {
            stulp_kiekis++;
        }
        while (input_file >> v >> p)
        {
            Studentas naujas_st;
            naujas_st.vardas = v;
            naujas_st.pavarde = p;
            for(int i=0;i<stulp_kiekis-3;i++)
            {
                int nd;
                if (!(input_file >> nd)||(nd>10)||(nd<0))
                {
                    cout << "Nepavyko perskaityti namu darbo rezultato is failo." << endl;
                    cout << "Tarp duomenu yra netikslumu, pvz. namu darbo pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
                    return 1;
                }
                naujas_st.ND.push_back(nd);
            }
            if (!(input_file >> naujas_st.Egz)||(naujas_st.Egz>10)||(naujas_st.Egz<0))
            {
                cout << "Nepavyko perskaityti egzamino rezultato is failo." << endl;
                cout << "Tarp duomenu yra netikslumu, pvz. egzamino pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
                return 1;
            }
            double nd_suma = accumulate(naujas_st.ND.begin(), naujas_st.ND.end(), 0.0);
            naujas_st.galutinis1 = rezultatas(nd_suma, naujas_st.ND.size(), naujas_st.Egz);
            double mediana = Med(naujas_st.ND);
            naujas_st.galutinis2 = rezMed(mediana, naujas_st.Egz);
            studentai.push_back(naujas_st);
            stud_sk++;
        }
        input_file.close();
    }
    else
    {
        cout<<"Neteisingas pasirinkimas"<<endl;
        return 1;
    }
    sort(studentai.begin(),studentai.end(),palyginimasVardai);
    char pasirinkimas;
    cout<<"Jeigu norite gauti galutini bala su vidurkiu - parasykite 'V' raide, jeigu su mediana - 'M'"<<endl;
    cin>>pasirinkimas;
    //---------------------------------------------------------Duomenu isvedimas----------------------------------------------------------
    char pasirinkimas4;
    cout<<"Jeigu norite gauti rezultata ekrane rasykite 'E', jeigu faile 'F'"<<endl;
    cin>>pasirinkimas4;
    if(pasirinkimas4=='E'||pasirinkimas4=='e')
    {
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<left;
        if (pasirinkimas=='V'||pasirinkimas=='v')
        {
            cout<<"Galutinis(Vid.)"<<endl;
        }
        else if(pasirinkimas=='M'||pasirinkimas=='m')
        {
            cout<<"Galutinis(Med.)"<<endl;
        }
        else
        {
            cout<<"Neteisingas pasirinkimas";
            return 1;
        }
        cout<<"------------------------------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<stud_sk;i++)
        {
            cout<<setw(20)<<left<<studentai[i].vardas<<setw(20)<<left<<studentai[i].pavarde<<setw(20)<<left;
            if (pasirinkimas=='V'||pasirinkimas=='v')
            {
                cout<<fixed<<setprecision(2)<<studentai[i].galutinis1<<endl;
            }
            else cout<<fixed<<setprecision(2)<<studentai[i].galutinis2<<endl;
        }
        cout << "--------------------------------------------------"<<endl;
        for (auto &studentas : studentai)
        {
            cout << "Objekto saugojimo atmintyje adresas studento " << studentas.vardas << " " << studentas.pavarde << ": "<< &studentas << endl;
        }
    }
    else if(pasirinkimas4=='F'||pasirinkimas4=='f')
    {
        ofstream outputFile("rezultatai.txt");
        outputFile <<setw(20)<<left<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<left;
        if (pasirinkimas=='V'||pasirinkimas=='v')
        {
            outputFile<<"Galutinis(Vid.)"<<endl;
        }
        else if(pasirinkimas=='M'||pasirinkimas=='m')
        {
            outputFile<<"Galutinis(Med.)"<<endl;
        }
        else
        {   cout<<"Neteisingas pasirinkimas";
            return 1;
        }
        outputFile<<"------------------------------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<stud_sk;i++)
        {
            outputFile<<setw(20)<<left<<studentai[i].vardas<<setw(20)<<left<<studentai[i].pavarde<<setw(20)<<left;
            if (pasirinkimas=='V'||pasirinkimas=='v')
                {
                    outputFile<<fixed<<setprecision(2)<<studentai[i].galutinis1<<endl;
                }
            else    outputFile<<fixed<<setprecision(2)<<studentai[i].galutinis2<<endl;
        }
        outputFile.close();
    }
    return 0;
}
