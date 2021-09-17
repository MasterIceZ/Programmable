function Deque() {
    let deq = [];
    this.push_back = function(x){
        deq.push(x);
    }
    this.pop_back = function(){
        deq.pop();
    }
    this.push_front = function(x){
        deq.unshift(x);
    }
    this.pop_front = function(){
        deq.shift();
    }
    this.back = function(){
        return deq[deq.length - 1]
    }
    this.front = function(){
        return deq[0];
    }
    this.empty = function(){
        return deq.length === 0;
    }
    this.__debug = function(){
        console.log(deq)
    }
}

//let deq = new Deque();