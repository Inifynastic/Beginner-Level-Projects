#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Books{
	private:
		std::string BookTitle;
		int BookId;
	
	public:
		Books(std::string Title, int Id){
			BookTitle = Title;
			BookId = Id;
			
			std::ofstream BookData("BookData.txt", std::ios::app);
			BookData << Id << " | " << Title <<std::endl;
			
			BookData.close();
		}
		void DisplayBook(){
			std::cout<<"Book Title: "<<BookTitle<<std::endl;
			std::cout<<"Book Id: "<< BookId<<std::endl;
		}
};

class Members{
	private:
		std::string MemberName;
		int MemberId;
	
	public:
		Members(std::string Name, int Id){
			MemberName = Name;
			MemberId = Id;
			
			std::ofstream MemberData("MemberData.txt", std::ios::app);
			MemberData << Id << " | " << Name <<std::endl;
			
			MemberData.close();
		}
		
		void DisplayMembers(){
			std::cout<<"Member Name: "<<MemberName<<std::endl;
			std::cout<<"Member Id: "<< MemberId<<std::endl;
		}
};


void AddMembers(std::vector<Members>& Memberlist, std::string Name, int Id){
	Members NewMember(Name, Id);
	Memberlist.push_back(NewMember);
	
	
}

void AddBooks(std::vector<Books>& Booklist, std::string Title, int Id){
	Books NewBook(Title, Id);
	Booklist.push_back(NewBook);
	

	
}

void DisplayBooks(std::vector<Books>& Booklist){
	int Length = Booklist.size();
	for(size_t i{0}; i < Length; i++){
		Booklist[i].DisplayBook();
		std::cout<<std::endl;
	}
}

void DisplayMembers(std::vector<Members>& Memberlist){
	int Length = Memberlist.size();
	for(size_t i{0}; i < Length; i++){
		Memberlist[i].DisplayMembers();
		std::cout<<std::endl;
	}
}

void LoadData(std::vector<Books>& Booklist, std::vector<Members>& Memberlist){
	
	std::string DataStore;
	std::string Name{ };
	size_t CurrentPoint{};
	int ID{0};
	char DataPointer{0};
	bool running{};
	
	
	std::ifstream BookData("BookData.txt", std::ios::in);			//Fix Me Please
	while (std::getline(BookData, DataStore)){
		for(size_t i{0} ;i < DataStore.size(); i++){
			
			if(DataStore[i] != ' ' && DataStore[i] != '|'){
				DataPointer = DataPointer + DataStore[i];
			}
			if(DataStore[i] == '|'){
				ID = static_cast<int>(DataPointer);
				CurrentPoint = i;
				break;
			}
		}
		for(size_t i{CurrentPoint}; i < DataStore.size(); i++){
			if(DataStore[i] != ' '){
				Name = Name + DataStore[i];
			}
		}
		AddBooks(Booklist, Name, ID);
		BookData.close();
		
	}	

	
	std::ifstream MemberData("MemberData.txt", std::ios::in);			//Fix Me too please
	while (std::getline(MemberData, DataStore)){
		for(size_t i{0} ;i < DataStore.size(); i++){
			
			if(DataStore[i] != ' ' && DataStore[i] != '|'){
				DataPointer = DataPointer + DataStore[i];
			}
			if(DataStore[i] == '|'){
				ID = static_cast<int>(DataPointer);
				CurrentPoint = i;
				break;
			}
		}
		for(size_t i{CurrentPoint}; i < DataStore.size(); i++){
			if(DataStore[i] != ' '){
				Name = Name + DataStore[i];
			}
		}
		AddMembers(Memberlist, Name, ID);
		BookData.close();
	}
	
}

int main(){
	std::vector<Books> Booklist;
	std::vector<Members> Memberlist;
	LoadData(Booklist, Memberlist);
	int Answer;
	
	std::cout<<"1 - Add Book."<<std::endl;
	std::cout<<"2 - Add Members."<<std::endl;
	std::cout<<"3 - Display Books."<<std::endl;
	std::cout<<"4 - Display Members."<<std::endl;
	
	bool running = true;
	while(running){
		std::string Name;
		int Id;
		
		std::cout<<"What do you wanan do?";
		std::cin>> Answer;

		switch(Answer) {
			case 1:
				std::cout<<"Id: ";
				std::cin>>Id;
				std::cout<<"Name: ";
				std::cin.ignore();
				std::getline(std::cin, Name);
				AddBooks(Booklist, Name, Id);
				break;
			case 2:
				std::cout<<"Id: ";
				std::cin>>Id;
				std::cout<<"Name: ";
				std::getline(std::cin, Name);
				AddMembers(Memberlist, Name, Id);
				break;
			case 3:
				DisplayBooks(Booklist);
				break;
			case 4:
				DisplayMembers(Memberlist);
				break;
			default:
				running = false;
				break;
			
		}
	}
}
