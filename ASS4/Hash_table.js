let linked_list = require("./linked_list");
let StringHash = require("./StringHash");
let IntHash = require("./IntHash");
let Hashable = require("./hashVal");


class Hash_table{
    #table;
    #size;
    #currSize;
    constructor(size){
        this.#table=new Array(size);
        this.#currSize=0;
        this.#size=size;
    }
    hash(data){
        let hash_val=data.hashVal();
        return hash_val%this.#size;
    }
    insert(data){
        console.log(this.#size);
        let index=data.hashVal(this.#size);
        if(this.#table[index]==null){
            this.#table[index]=new linked_list();
        }
        this.#table[index].insertL(data);
        // currSize++;
    }
    print(){
        for(let i=0;i<this.#size;i++){
           if (this.#table[i]!=null){
               for (let j=0;j<this.#table[i].length;j+=2){
                   console.log(this.#table[i][j]+" "+this.#table[i][j+1].getTop().getDatNode());
               }
           }
                
            
        }
    }

    toDict(){
        let dict={};
        for(let i=0;i<this.#size;i++){
              if (this.#table[i]!=null){
                for (let j=0;j<this.#table[i].length;j+=2){
                     dict[this.#table[i][j]]=this.#table[i][j+1].getTop().getDatNode();
                }
              }
                 
                
          }
            return dict;
    }

    put(k,v){
        // if table[k] is null
        // create new linked list
        // insert v
        // else
        // insert v
        let index=k.hashVal(this.#size);
        
        if(this.#table[index]==null){
            this.#table[index]=[];
            this.#table[index].push(k.getData());

            
            // this.#table[index][0]=k.getData();
            this.#table[index][1]=new linked_list();


            this.#table[index][1].insertL(v);

        }else{
                // check the this.#table[index][ this.#table[index].length] is the same as k.getData()
                let at=-1;
                for(let i=0;i<this.#table[index].length;i+=2){
                    if(this.#table[index][i]==k.getData()){
                        at=i;
                    }
                }

                if(at!=-1){
                    this.#table[index][ at+1].insertL(v);
                }
                else{
                    this.#table[index].push(k.getData());
                    this.#table[index].push(new linked_list());
                    this.#table[index][ this.#table[index].length-1].insertL(v);
                 
                }




        }

        // if (this.#table[index].inside(v)){
        //     console.log("data is already in the list");
        //     return;
        // }
       



    }
    updatePercentage(lenData){
        for(let i=0;i<this.#size;i++){
            if (this.#table[i]!=null){
              
                for (let j=0;j<this.#table[i].length;j+=2){
                    
                   let a= this.#table[i][j+1].getTop().getDatNode()
                   this.#table[i][j+1].insertL(a/lenData);
                }
            }
                 
             
         }
    
    }

    get(k){
        // return table[k]
        let index=k.hashVal(this.#size);
        if(this.#table[index]==null){
            return undefined;
        }
        else{
            let at=-1;
            for(let i=0;i<this.#table[index].length;i+=2){
                if(this.#table[index][i]==k.getData()){
                    at=i;
                }
            }
            if(at!=-1){
                return this.#table[index][at+1].getTop().getDatNode();
            }
            else{
                return undefined;
            }

        }
        
    }
    contains(k){
    return this.get(k)!=null;
    }
    isEmpty(){
        return this.#currSize==0;
    }
}
module.exports = Hash_table;
