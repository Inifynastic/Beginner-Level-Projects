require 'yaml'


$studentCount = 0
$studentList = []
$teacherCount = 0
$teacherList = []

class Student
	def initialize(name, age, course)
		@name = name
		@age = age
		@course = course
	end
	
	def displays
		print "Name: "
		puts @name
		print "Age: "
		puts @age
		print "Course: "
		puts @course
	end
end

class Teacher
	def initialize(name, age, subject)
		@name = name
		@age = age
		@subject = subject
	end
	
	def displays
		print "Name: "
		puts @name
		print "Age: "
		puts @age
		print "Subject: "
		puts @subject
	end
	
end


def displayStudents
	(0..$studentCount - 1).each do |i|
		$studentList[i].displays
		puts " "
	end
end

def displayTeacher
	(0..$teacherCount - 1).each do |i|
		$teacherList[i].displays
		puts " "
	end
end

def deleteStudent(index)
	$studentList[index] = 0
	
	(0..$studentCount - 1).each do |i|
		if($studentList[index])
			$studentList[index] = $studentList[index]
		end
	end
end

def deleteTeacher(index)
	$teacherList[index] = 0
	
	(0..$teacherCount - 1).each do |i|
		if($teacherList[index])
			$teacherList[index] = $teacherList[index]
		end
	end
end

def addData
	while(true)
		puts "1 For Student and 2 For Teacher"
		puts "Leave empty to exit"
		print "Your Respond: "
		answer = gets
		answer = answer.to_i
	
		if(answer == 1)
			print "Enter name: "
			name = gets.chomp
			print "Enter age: "
			age = gets
			age = age.to_i
			print "Enter course: "
			course = gets.chomp
			dataYAML = {type: "student", name: name, age: age, course: course}
			
			File.open("data.yaml", "a") do |f|
				f.write(dataYAML.to_yaml)
			end
			
			$studentList[$studentCount] = Student.new(name, age, course)
			$studentCount = $studentCount + 1
		elsif(answer == 2)
			print "Enter name: "
			name = gets.chomp
			print "Enter age: "
			age = gets
			age = age.to_i
			print "Enter subject: "
			subject = gets.chomp
		
			dataYAML = {type: "teacher", name: name, age: age, subject: subject}
			File.open("data.yaml", "a") do |f|
				f.write(dataYAML.to_yaml)
			end
			
			$teacherList[$teacherCount] = Teacher.new(name, age, subject)
			$teacherCount = $teacherCount + 1
		else
			break
		end
		
	end
end

def loadData
	dataYAML = YAML.load_stream(File.read("data.yaml"))
	dataYAML.each do |f|
		if(f[:type] == 'student')
			$studentList[$studentCount] = Student.new(f[:name], f[:age], f[:course])
			$studentCount = $studentCount + 1
		else
			$teacherList[$teacherCount] = Teacher.new(f[:name], f[:age], f[:subject])
			$teacherCount = $teacherCount + 1
		end
	end
end

loadData
addData
puts " "
displayStudents
displayTeacher
