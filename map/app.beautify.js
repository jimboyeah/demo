var Student = function() {
    function e(e, t, r) {
        this.firstName = e, this.middleInitial = t, this.lastName = r, this.fullName = e + " " + t + " " + r;
    }
    return e.prototype.greet = function() {
        return "Hi " + this.firstName;
    }, e;
}();

function greeter(e) {
    return "Hello, " + e.firstName + " " + e.lastName;
}

var user = new Student("Jane", "M.", "User");

console.log(user.greet()), console.log(greeter(user));