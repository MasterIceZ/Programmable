function Stack() {
    let st = [];
    this.push = function(x){
        st.push(x);
    }
    this.pop = function(){
        st.pop();
    }
    this.top = function(){
        return st[st.length - 1];
    }
    this.empty = function(){
        return st.length === 0;
    }
    this.__debug = function(){
        console.log(st)
    }
}

//let stack = new Stack();