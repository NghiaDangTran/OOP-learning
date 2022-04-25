let Hash_table = require("./Hash_table");
let linked_list = require("./linked_list");
let StringHash = require("./StringHash");
let IntHash = require("./IntHash");
let Hashable = require("./hashVal");
let Huffman_Trees = require("./2_Huffman_Trees");
const fs = require('fs');
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the huffman encoding class
 *  but I fells it need a sperate class so i add it in the main class
 */




function main() {

    let table = new Hash_table(500);
    // make a table with plenty of space for the hash table



    // if you want to read from a file
    // update the file name 'input.txt'
    let str = fs.readFileSync('input.txt', 'utf8').split('\n');
    // read the file and split it by new line using the build in library


    for (let i = 0; i < str.length; i++) {
        // for each line in the file
        for (let j = 0; j < str[i].length; j++) {
            // for each character in the line
            let charData = str[i][j];

           
            let char;
            if (charData.match(/[0-9]/)) {
                //cast the char to int
                char = new IntHash(parseInt(charData));
                // if the char is a number
            }
            else {
                // if the char is a string
                char = new StringHash(str[i][j]);
            }
            if (table.get(char) != null) {
                // if the char is in the table then update the count
                table.put(char, table.get(char) + 1);
            }
            else {
                // if the char is not in the table then add it
                table.put(char, 1);
            }
        }
    }
    table.updatePercentage(str.length);
    // update the percentage of each char in the table



  
    let data = table.toDict();// get the data from the table
    var array = [];
    for (let i in data) {
        // for each pair in the data
        // push into the array of huffman tree
        array.push(new Huffman_Trees(i, data[i]));
    }
    function compare(a, b) {
        // customer compare function
        return a.compareTo(b);
    }
    array.sort(compare);
    // sort by the compare function
    while (array.length > 1) {
        // while there is more than one tree in the array
        array[0] = array[0].Combine(array[0], array[1]);
        // combine the first two trees
        array.splice(1, 1);
        // remove the second tree
        array.sort(compare);
        // sort the array
        //repeat
    }
    let dict = {};
    // to make everything faster
    // just take the encoding the tree 
    // then make it a dictionary
    array[0].encodingALl(array[0], "");
    array[0].encoding_dict(array[0], dict);

    let output = "";
    for (let i = 0; i < str.length; i++) {
        // for each line in the file
        for (let j = 0; j < str[i].length; j++) {
            // for each character in the line
            output += dict[str[i][j]];
            // add the encoding to the output
            output += " ";
        }
        output += "\n";
    }

    // console.log(output);

    // write the output to the file
    //if you want to write to a file
    // update the file name 'output.txt'
    fs.writeFile('output.txt', output, (err) => {
        if (err) throw err;
        console.log('The file has been saved!');
    }

    );


    // custom function to decode the file using hard fored code
    // function decode(data, dict) {
    //     let result = data.split(" ");
    //    // console.log(result);
    //     let output = "";
    //     for (let i = 0; i < result.length; i++) {
    //         if (result[i].includes("\n")) {
    //             output += "\n";
    //             result[i]=result[i].replace("\n","");
    //         }
    //         for (let j = 0; j < Object.keys(dict).length; j++) {
    //             if (dict[Object.keys(dict)[j]] == result[i]) {
    //                 output += Object.keys(dict)[j];
    //                 break;
    //             }
    //         }
          
    //     }
    //     console.log(output);


    // }
    // // console.log(dict);
    // decode(output, dict);



}

// call the main function
main();