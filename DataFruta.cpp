#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		return 0;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes: public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int n;
		string nome;
		cout<<"Nomes: Quantas entradas :";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite nome: ";
			getline(cin>>ws,nome);
			lista.push_back(nome);
		}
	}
		
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
		int metade=static_cast<int>((lista.size()/2)+lista.size()%2);
		//cout<<"metade:"<<metade<<endl;
		cout<<"Mediana: "<<lista.at(metade-1)<<endl;
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
		cout<<"Menor: "<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};

class ListaDatas: public Lista  {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int n;
		int dia,mes,ano;
		
		cout<<"Data: Quantas entradas:";
		cin>>n;
		//getchar();
		for(int i=0;i<n;i++){
			cout<<"Digite dia mes ano: ";
			cin>>dia>>mes>>ano;
			Data d1(dia,mes,ano);
			//str_d1=d1.toString();
			//cout<<"str_d1: "<<str_d1<<endl;
			lista.push_back(d1);
			//cout<<lista.at(<<endl;
		}
	}
	
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
		int metade=static_cast<int>((lista.size()/2)+lista.size()%2);
		//cout<<"metade:"<<metade<<endl;
		cout<<"Mediana: "<<lista.at(metade-1).toString()<<endl;
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
		cout<<"Menor: "<<lista.front().toString()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
		cout<<"Maior: "<<lista.back().toString()<<endl;
	}
};

class ListaSalarios: public Lista  {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		float salario;
		cout<<"Salarios: Quantas entradas:";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite salario: ";
			cin>>salario;
			lista.push_back(salario);
			//cout<<lista.at(i)<<endl;
		}
	}
			
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
		int metade=static_cast<int>((lista.size()/2));//+lista.size()%2);
		if(lista.size()%2){
			cout<<"Mediana: "<<(lista.at(metade))<<endl;
		}else{
			cout<<"Mediana: "<<((lista.at(metade-1)+lista.at(metade))/2)<<endl;
		}
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar o menor dos salarios" << endl;
		cout<<"Menor:"<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar o maior dos salarios" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};


class ListaIdades:public Lista  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		int idade;
		cout<<"Idades: Quantas entradas:";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite idade: ";
			cin>>idade;
			lista.push_back(idade);
			//cout<<lista.at(i)<<endl;
		}
	}
	
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		int metade=static_cast<int>((lista.size()/2));//+lista.size()%2);
		if(lista.size()%2){
			cout<<"Mediana: "<<(lista.at(metade))<<endl;
		}else{
			cout<<"Mediana: "<<((lista.at(metade-1)+lista.at(metade))/2)<<endl;
		}
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar a menor das idades" << endl;
		cout<<"Menor:"<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar a maior das idades" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	//ListaNomes listaNomes;
	//listaNomes.entradaDeDados();
	//listaDeListas.push_back(&listaNomes);
	
	//ListaDatas listaDatas;
	//listaDatas.entradaDeDados();
	//listaDeListas.push_back(&listaDatas);
	
	//ListaSalarios listaSalarios;
	//listaSalarios.entradaDeDados();
	//listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    
