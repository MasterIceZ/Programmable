function Queue() {
    let qu = [];
    this.push = function(x){
        qu.push(x);
    }
    this.pop = function(){
        qu.shift();
    }
    this.front = function(){
        return qu[0];
    }
    this.empty = function(){
        return qu.length === 0;
    }
    this.__debug = function(){
        console.log(qu)
    }
}

//let queue = new Queue();