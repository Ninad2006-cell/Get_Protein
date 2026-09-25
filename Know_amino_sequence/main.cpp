#include<bits/stdc++.h>
#include<cctype>
#include<algorithm>
using namespace std;

unordered_map<string, string> har_govind_khorana_codon_table(){
    return {
        // Codon starting with U
        {"UUU", "Phe"}, {"UUC", "Phe"}, {"UUA", "Leu"}, {"UUG", "Leu"},
        {"UCU", "Ser"}, {"UCC", "Ser"}, {"UCA", "Ser"}, {"UCG", "Ser"},
        {"UAU", "Tyr"}, {"UAC", "Tyr"}, {"UAA", "Stop"}, {"UAG", "Stop"},
        {"UGU", "Cys"}, {"UGC", "Cys"}, {"UGA", "Stop"}, {"UGG", "Trp"},

        //Codon starting with C
        {"CUU", "Leu"}, {"CUC", "Leu"}, {"CUA", "Leu"}, {"CUG", "Leu"},
        {"CCU", "Pro"}, {"CCC", "Pro"}, {"CCA", "Pro"}, {"CCG", "Pro"},
        {"CAU", "His"}, {"CAC", "His"}, {"CAA", "Gln"}, {"CAG", "Gln"},
        {"CGU", "Arg"}, {"CGC", "Arg"}, {"CGA", "Arg"}, {"CGG", "Arg"},

        //Codon starting with A
        {"AUU", "Ile"}, {"AUC", "Ile"}, {"AUA", "Ile"}, {"AUG", "Met"},
        {"ACU", "Thr"}, {"ACC", "Thr"}, {"ACA", "Thr"}, {"ACG", "Thr"},
        {"AAU", "Asn"}, {"AAC", "Asn"}, {"AAA", "Lys"}, {"AAG", "Lys"},
        {"AGU", "Ser"}, {"AGC", "Ser"}, {"AGA", "Arg"}, {"AGG", "Arg"},

        //Codon starting with G
        {"GUU", "Val"}, {"GUC", "Val"}, {"GUA", "Val"}, {"GUG", "Val"},
        {"GCU", "Ala"}, {"GCC", "Ala"}, {"GCA", "Ala"}, {"GCG", "Ala"},
        {"GAU", "Asp"}, {"GAC", "Asp"}, {"GAA", "Glu"}, {"GAG", "Glu"},
        {"GGU", "Gly"}, {"GGC", "Gly"}, {"GGA", "Gly"}, {"GGG", "Gly"}
    }; 
}

unordered_map<string, string> get_codon_anticodon(){
    return {
        {"A", "U"}, {"U", "A"}, {"C", "G"}, {"G", "C"}
    };
}

unordered_map<string, string> get_name_of_amino(){
    return {
        {"Ala", "Alanine"},
        {"Arg", "Arginine"},
        {"Asn", "Asparagine"},
        {"Asp", "Aspartic acid"},
        {"Cys", "Cysteine"},
        {"Gln", "Glutamine"},
        {"Glu", "Glutamic acid"},
        {"Gly", "Glycine"},
        {"His", "Histidine"},
        {"Ile", "Isoleucine"},
        {"Leu", "Leucine"},
        {"Lys", "Lysine"},
        {"Met", "Methionine"},
        {"Phe", "Phenylalanine"},
        {"Pro", "Proline"},
        {"Ser", "Serine"},
        {"Thr", "Threonine"},
        {"Trp", "Tryptophan"},
        {"Tyr", "Tyrosine"},
        {"Val", "Valine"},
        {"Stop", "Termination (Stop Codon)"}
    };
}

string get_the_amino_sequence(string& mrna_sequence, unordered_map<string, string>& codon_table, 
                                unordered_map<string, string>& amino_acids){
    int end = mrna_sequence.length() - mrna_sequence.length() % 3;
    string getSequence = "";
    int i = 0;
    string start = "";
    start = mrna_sequence[0];
    start += mrna_sequence[1];
    start += mrna_sequence[2];
    cout << "start: " << start << "\n";
    if(start != "AUG"){
        return "";
    }
    while(i < end){

        string codon = mrna_sequence.substr(i, 3);

        if(codon_table.find(codon) != codon_table.end()){

            string str = codon_table[codon];

            if(str == "Stop"){
                return getSequence;
            }

            if(!getSequence.empty()){
                getSequence += "->";
            }

            getSequence += amino_acids[str];
        }

        i += 3;
    }

    return getSequence;
}

string preprocess_input(string& mrna){
    int idx = 0;
    for(int i = 0; i < mrna.length(); i++){
        if(mrna[i] == 'A' || mrna[i] == 'U' || mrna[i] == 'C' || mrna[i] == 'G'){
            mrna[idx++] = mrna[i];
        }
    }
    return mrna.substr(0, idx);
}

int main(){
    unordered_map<string, string> codon_list = har_govind_khorana_codon_table();
    string mrna;
    getline(cin, mrna);
    transform(mrna.begin(), mrna.end(), mrna.begin(), ::toupper);
    mrna = preprocess_input(mrna);
    unordered_map<string, string> amino_acid = get_name_of_amino();
    string amino_sequence = get_the_amino_sequence(mrna, codon_list, amino_acid);
    cout << "Processed: " << mrna << endl;
    cout << "Amino: " << amino_sequence << endl;
    return 0;
}