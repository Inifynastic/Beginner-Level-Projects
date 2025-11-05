#include <iostream>
#include <vector>

class Members{
	private:
		std::string Full_Name;
		int Age;
		int PhoneNumber;
		std::string Residents;
	public:
		Members(std::string Name, int Age1, int Phone, std::string Resident){
			Full_Name = Name;
			Age = Age1;
			PhoneNumber = Phone;
			Residents = Resident;
		}
		void Display(){
			std::cout<<"Name: "<<Full_Name<<std::endl;
			std::cout<<"Age: "<<Age<<std::endl;
			std::cout<<"Phone Number: "<<PhoneNumber<<std::endl;
			std::cout<<"Residents: " <<Residents<<std::endl;
		}
};

Members AddMember(){
	std::string Name = ""; 
	int Age1 = 0; 
	int Phone = 0; 
	std::string Resident = "";
	
	std::cout<<"Name: ";
	std::cin>>Name;
	std::cout<<"Age: ";
	std::cin>>Age1;
	std::cout<<"Phone: ";
	std::cin>>Phone;
	std::cout<<"Residents: ";
	std::cin>>Resident;

	if (Name != "" && Age1 != 0 && Phone != 0 && Resident != "")
	{
		Members* Member = new Members(Name, Age1, Phone, Resident);
		std::cout<<"Successful!"<<std::endl;
		return Member;
	}
	std::cout<<"Unsuccessful!"<<std::endl;
	return 0;
}

void SearchOnList(std::vector<Members*> memberslist){
	int value;
	std::cout<<"Minimum Value: "<< "0" <<std::endl;
	std::cout<<"Maximum Value: "<< memberslist.size() <<std::endl;
	std::cout<<std::endl;
	std::cout<<"Type the value to check the user detail or Type -1 to Check the entire Database."<<std::endl;
	std::cout<<"Your Responce: ";
	std::cin>>value;
	
	if(value == -1){
		for (size_t i{0}; i <= memberslist.size() - 1 ; i++){
			std::cout<<"ID: "<< i <<std::endl;
			memberslist[i]->Display();
			std::cout<<"----------------------------------------------"<<std::endl;
		}
		std::cout<<std::endl;
	}else{
		if (value > memberslist.size()){
			std::cout<<"Value does not exist"<<std::endl;
			return;
		}
		memberslist[value - 1]->Display();
	}
	return;
}

int main(){
	std::vector<Members*> memberslist;
	int value;
	while(true){
		std::cout<<"Press 1 for Add on list and 2 for Search on list."<<std::endl;
		std::cout<<"Your Responce:";
		std::cin>>value;
		switch (value)
		{
		case 1:
			memberslist.push_back(AddMember());
			break;
		case 2:
			SearchOnList(memberslist);
			break;
		default:
			break;
		}
	}
}
