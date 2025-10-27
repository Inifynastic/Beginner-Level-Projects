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
			
		}
		
		void DisplayMembers(){
			std::cout<<"Member Name: "<<MemberName<<std::endl;
			std::cout<<"Member Id: "<< MemberId<<std::endl;
		}
};


void AddMembers(std::vector<Members>& Memberlist, std::string Name, int Id, bool swi){
	Members NewMember(Name, Id);
	Memberlist.push_back(NewMember);
	
	if(swi){
		std::ofstream MemberData("MemberData.txt", std::ios::app);
		MemberData << Id << "|" << Name <<std::endl;
		
		MemberData.close();
	}
}

void AddBooks(std::vector<Books>& Booklist, std::string Title, int Id, bool swi){
	Books NewBook(Title, Id);
	Booklist.push_back(NewBook);
	
	if(swi){
		std::ofstream BookData("BookData.txt", std::ios::app);
		BookData << Id << "|" << Title <<std::endl;
		
		BookData.close();
	}
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
	int DataPointer{0};
	bool running{};
	
	
	std::ifstream BookData("BookData.txt", std::ios::in);
	while (std::getline(BookData, DataStore)){
		size_t Seperator = DataStore.find("|");
		std::string temp = DataStore.substr(0, Seperator + 2);
		ID = stoi(temp);
		Name = DataStore.substr(Seperator);
		
		
		AddBooks(Booklist, Name, ID, false);
	}	
	BookData.close();

	
	std::ifstream MemberData("MemberData.txt", std::ios::in);
	while (std::getline(MemberData, DataStore)){
		size_t Seperator = DataStore.find("|");
		std::string temp = DataStore.substr(0, Seperator);
		ID = stoi(temp);
		Name = DataStore.substr(Seperator + 2);
		
		
		AddMembers(Memberlist, Name, ID, false);
		MemberData.close();
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
				AddBooks(Booklist, Name, Id, true);
				break;
			case 2:
				std::cout<<"Id: ";
				std::cin>>Id;
				std::cout<<"Name: ";
				std::getline(std::cin, Name);
				AddMembers(Memberlist, Name, Id, true);
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
