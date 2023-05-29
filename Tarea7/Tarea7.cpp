#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void printStack(stack<int> pila) {
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

//1: O(n)
void eliminarPosicionesPila(stack<int>& pila, list<int> elim){
    stack<int> auxP;
    int pos = 0;

    while(!elim.empty() && !pila.empty()){
        int value = pila.top();

        if(pos==elim.front()){
            elim.pop_front();
        }else{
            auxP.push(value);
        }

        pila.pop();
        pos++;
    }

    while(!auxP.empty()){
        int value= auxP.top();

        auxP.pop();
        pila.push(value);
    }
}
//3: O(n)
bool verificarOrdenadoCola(stack<int>& pila){
    stack<int> aux;
    int value;
    bool organized=true;

    while(!pila.empty() && organized){
        
        int value = pila.top();

        if(aux.empty()){
            aux.push(value);
            pila.pop();
        }else if(aux.top()<value){
            cout<<"not organized"<<endl;
            organized= false;
        }else{
            aux.push(value);
            pila.pop();
        }
        
    }

    while(!aux.empty()){
        int value= aux.top();

        aux.pop();
        pila.push(value);
    }
    return organized;
}
//4: O(n)
int obtenerMenorCosto(list<int> nums){
    nums.sort();
    int cost=0;

    while (nums.size() > 1) {
        int a = nums.front();
        nums.pop_front();
        int b = nums.front();
        nums.pop_front();

        int sum = a + b;
        cost += sum;

        nums.push_front(sum);
        nums.sort();
    }

    return cost;
}
//5: O(n**2)
int evaluarExpresion(list<char> c) {
    string op;
    list<string> operations;

    while (!c.empty()) {
        char current = c.front();
        c.pop_front();

        if (current == '(') {
            if (!op.empty()) {
                operations.push_back(op);
            }
            op = current;
        } else if (current == ')' && !op.empty()) {
            op += current;
            operations.push_back(op);
            op = "";
        } else {
            op += current;
        }

        if (c.empty()) {
            operations.push_back(op);
        }
    }

    list<int> results;
    list<char> oper;

    while (!operations.empty()) {
        string current = operations.front();
        operations.pop_front();
        list<int> num;
        char operador;
        int res;


        if (current[0] == '(' || current[current.length() - 1] == ')') {
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') {
                    if (current[i] != '+' && current[i] != '-' && current[i] != '*') {
                        num.push_back(current[i] - '0');
                    } else {
                        operador = current[i];
                    }
                }
            }

            int num1;
            int num2;

            switch (operador) {
                case '+':
                    num1 = num.front();
                    num.pop_front();
                    num2 = num.front();
                    num.pop_front();
                    results.push_back(num1 + num2);
                    break;

                case '-':
                    num1 = num.front();
                    num.pop_front();
                    num2 = num.front();
                    num.pop_front();
                    results.push_back(num1 - num2);
                    break;

                case '*':
                    num1 = num.front();
                    num.pop_front();
                    num2 = num.front();
                    num.pop_front();
                    results.push_back(num1 * num2);
                    break;

                default:
                    break;
            }
        } else {
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') {
                    if (current[i] != '+' && current[i] != '-' && current[i] != '*') {
                        results.push_back(current[i] - '0');
                    } else {
                        oper.push_back(current[i]);
                    }
                }
            }
        }
    }
    
    int final;
    while(!results.empty()){
        int num1;
        int num2;
        char op;
        

        if(oper.empty()){
            final=results.front();
            break;
        }else{
            if(final!='\0'){
                num1=final;
            }else{
                num1=results.front();
                results.pop_front();
            }

            num2=results.front();
            results.pop_front();
            
            op= oper.front();
            oper.pop_front();

            switch (op) {
                case '+':
                    final=num1+num2;
                break;

                case '-':
                    final=num1-num2;
                break;

                case '*':
                    final=num1*num2;
                break;

                default:
                break;
            }
        }

        
    }

    return final;
}
//6: O(nlog n)
int verificarRepetidos(queue<int>& col) {
    queue<int> aux;
    int rep=0;

    map<char, list<int>> resultado;

    while (!col.empty()){
        int current= col.front();
        col.pop();
        aux.push(current);
        resultado[current].push_front(1);
    }

    while (!aux.empty())
    {
        int current= aux.front();
        aux.pop();
        col.push(current);
    }
    for (map<char, list<int>>::iterator it = resultado.begin(); it != resultado.end(); ++it){
        list<int> values = it->second;
        if(values.size()>1){
            rep++;
        }
    }

    return rep;
}
//7: O(nlog n)
map<char, list<int>> obtenerPosicionesOcurrencias(string& cad) {
    map<char, list<int>> resultado;

    for (int i = 0; i < cad.length(); i++) {
        char caracter = cad[i];
        resultado[caracter].push_back(i);
    }

    return resultado;
}
//8: O(n**2)
vector<list<pair<int, int>>> crearMatrizDispersa(vector<vector<int>> mat) {
    vector<list<pair<int, int>>> answer;

    for (int i = 0; i < mat.size(); i++) {
        vector<int> row = mat[i];
        list<pair<int, int>> pairList;
        for (int j = 0; j < row.size(); j++) {
            int col = row[j];
            if (col != 0) {
                pairList.push_back(make_pair(col, j));
            }
        }
        answer.push_back(pairList);
    }

    return answer;
}
//9: O(nlog n)
bool verificarRepetidosCola(queue<int>& col) {
    int rep = verificarRepetidos(col);
    return rep>0;
}
//10: O(n)
stack<int> filtrarNParesCola(queue<int> col, int n){
    stack<int> answer;

    while(n>0 || !col.empty()){
        int current = col.front();
        col.pop();
        if(current%2 ==0){
            answer.push(current);
        }
        n--;
    }

    return answer;
}

int main(){

    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    list<int> positions = {1, 3};
    list<int> suma = {3, 1, 4, 2};

    cout<<to_string(obtenerMenorCosto(positions))<<endl;
    cout<<to_string(obtenerMenorCosto(suma))<<endl;

    verificarOrdenadoCola(myStack);

    eliminarPosicionesPila(myStack, positions);

    printStack(myStack);

    myStack.push(2);

    verificarOrdenadoCola(myStack);

    list<char> operations= {'(', '1', '+', '3', ')', '-', '(','2','+','3',')', '*', '3'};

    cout<<evaluarExpresion(operations)<<endl;
    
    cout<<endl;

    queue<int> col;
    col.push(1);
    col.push(2);
    col.push(3);
    col.push(2);
    col.push(4);
    col.push(1);
    col.push(3);
    col.push(3);
    col.push(3);
    col.push(5);
    col.push(5);

    int repeated = verificarRepetidos(col);
    cout << "Numero de elementos repetidos: " << repeated << endl;

    string cadena = "abracadabra";
    map<char, list<int>> resultado = obtenerPosicionesOcurrencias(cadena);

    for (map<char, list<int>>::iterator it = resultado.begin(); it != resultado.end(); ++it) {
        char key = it->first;
        list<int> values = it->second;

        cout << "posiciones de " << key<< ": ";

        while(!values.empty()){
            int current= values.front();
            values.pop_front();
            if(!values.empty()){
                cout<< current<< ", ";
            }else{
                cout<< current<< endl;
            }
        }
    }

    cout<<endl;

    vector<vector<int>> matriz = {{0, 2, 0, 0},
                                  {0, 0, 0, 5},
                                  {0, 0, 0, 0},
                                  {1, 0, 3, 0}};

    vector<list<pair<int, int>>> matrizDispersa = crearMatrizDispersa(matriz);

    // Imprimir la matriz dispersa
    for (int i = 0; i < matrizDispersa.size(); i++) {
        list<pair<int, int>> row = matrizDispersa[i];
        cout << i << ": ";
        for (list<pair<int, int>>::iterator it = row.begin(); it != row.end(); ++it) {
            int dato = it->first;
            int pos = it->second;
            cout << "valor: " << dato << " col: " << pos << "    ";
        }
        cout << endl;
    }

    if(verificarRepetidosCola(col)){
        cout<<"Hay repetidos"<<endl;
    }

    queue<int> colita;
    colita.push(1);
    colita.push(2);
    colita.push(3);
    colita.push(4);
    colita.push(5);
    colita.push(6);

    int n = 2;

    stack<int> pilaPares = filtrarNParesCola(colita, n);

    cout << "Los primeros " << n << " numeros pares encontrados en la cola son: ";

    while (!pilaPares.empty()) {
        cout << pilaPares.top() << " ";
        pilaPares.pop();
    }

    cout << endl;

    return 0;
}