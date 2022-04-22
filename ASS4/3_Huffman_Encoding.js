let Hash_table = require("./Hash_table");
let linked_list = require("./linked_list");
let StringHash = require("./StringHash");
let IntHash = require("./IntHash");
let Hashable = require("./hashVal");
let Huffman_Trees = require("./2_Huffman_Trees");
const fs = require('fs');
function main() {
    let table = new Hash_table(500);
    // read the file as a string line by line
    
    const readline = require('readline');

    fs.readFile('input.txt', 'utf-8', (err, data) => {
        if (err) throw err;

    })

    let str = fs.readFileSync('input.txt', 'utf8').split('\n');
    // processLineByLine();

    // console.log(str);

    for (let i = 0; i < str.length; i++) {
        for (let j = 0; j < str[i].length; j++) {
            let charData = str[i][j];
            // char is a string create StringHash
            // if it is number create IntHash
            let char;
            if (charData.match(/[0-9]/)) {
                //cast the char to int
                char = new IntHash(parseInt(charData));
            }
            else {

                char = new StringHash(str[i][j]);
            }
            if (table.get(char) != null) {
                table.put(char, table.get(char) + 1);
            }
            else {
                table.put(char, 1);
            }
        }
    }
    table.updatePercentage(str.length);

    // console.log(table.toDict());
    let data = table.toDict();
    var array = [];
    for (let i in data) {
        array.push(new Huffman_Trees(i, data[i]));
    }
    function compare(a, b) {
        return a.compareTo(b);
    }
    array.sort(compare);
    while (array.length > 1) {
        array[0] = array[0].Combine(array[0], array[1]);
        array.splice(1, 1);
        array.sort(compare);
    }
    let dict = {};
    array[0].encodingALl(array[0], "");
    array[0].encoding_dict(array[0], dict);
    console.log(dict);

    let output = "";
    for (let i = 0; i < str.length; i++) {
        for (let j = 0; j < str[i].length; j++) {
            output += dict[str[i][j]];
            output += " ";
        }
        output += "\n";
    }

    console.log(output);


    fs.writeFile('output.txt', output, (err) => {
        if (err) throw err;
        console.log('The file has been saved!');
    }
    );
    





















}


main();