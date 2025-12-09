require 'json'
require 'digest'


$pwList = {}
	
def addUser(username, password)
	encryptedpassword = Digest::SHA256.hexdigest(password)
	$pwList[username] = encryptedpassword
end
	
def updateJSON
	data = JSON.generate($pwList)
	File.open("passwords.json", "w") do |file|
		file.write(data)
	end
end


addUser("Jhonson", "LongJonson")
addUser("CashBro", "AssBro")
addUser("TrashBro", "BashBro")
addUser("CatBoy", "FatBoy")
addUser("ArchUser", "FartUser")
addUser("Ubuntuistrash", "Arch-is-cool")
addUser("Money", "Jhonnyhoney")
updateJSON
