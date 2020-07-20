	var oo = { _value:1 };
	Object.defineProperty(oo,'value', {
		// value:9,
		// writable: false,
		enumerable: true,
		configurable: true,
		get: function(){
			console.log("get value...", this._value);
			return this._value;
		},
		set: function(value){
			this._value = value;
			console.log(`set value... ${this._value}`);
		}
	});

	var i = oo.value;
	var a = {};
	oo.value = a;
	oo.value = a;
