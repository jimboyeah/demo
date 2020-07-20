class Student {
	fullName: string;
	constructor(public firstName, public middleInitial, public lastName) {
		this.fullName = firstName + " " + middleInitial + " " + lastName;
	}
	greet(){
		return "Hi "+this.firstName;
	}
}

interface Person {
	firstName: string;
	lastName: string;
}

function greeter(person : Person) {
	return "Hello, " + person.firstName + " " + person.lastName;
}

var user = new Student("Jane", "M.", "User");
console.log(user.greet());
console.log(greeter(user));
