#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

//Todo esto con el objetivo de diminuir el tamano de lo que creamos
//Puedo crear N tipo de clases que reciben N tipos de datos a traves de la plantilla de la clase
template <typename T>
class Statistics{
    public:
        //Constuctor de la clase de manera generica
        Statistics(const std::vector<T>& data) : data(data) {
            if(data.empty()){
                throw std::invalid_argument("La lista debe contener elementos");
            }
        }

        //Calculo de la media del vector
        double mean() const{
            T sum = 0;
            for ( const T& value : data){
                sum += value;
            }
            return static_cast<double>(sum)/ data.size();
        }

        //Calculo de la desviacion estandar del vector
        double standarDeviation() const {
            double meanValue = mean();
            double sumSquares  = 0;
            for ( const T& value : data){
                sumSquares += (value - meanValue) * (value - meanValue);
            }
            return std::sqrt(sumSquares / data.size());
        }

    private:
        //Solo puedo accder dentro de la misma clase o clase amiga
        std::vector<T> data;
};


//Siempre es necesario que se llame main, es por donde entramos el progrma
int main() {
    try{
        //Templte tipo int
        std::vector<int> intData = {1,2,3,4,5};
        //Se crea instancia utilizando template
        Statistics<int> statsInt(intData);
        
        std::cout << "Media de intData: "<< statsInt.mean()<< std::endl;
        std::cout << "Desviacion estandar de intData: "<< statsInt.standarDeviation()<< std::endl;

        /*****************************************/

        //Tamplate tipo double
        std::vector<double> doubleData = {1.5,2.5,3.5,4.5,5.5};
        Statistics<double> statsDouble(doubleData);

        std::cout << "Media de doubleData: "<< statsDouble.mean()<< std::endl;
        std::cout << "Desviacion estandar de doubleData: "<< statsDouble.standarDeviation()<< std::endl;

        /*****************************************/
        //Caso de prueba de fallas del programa, donde el vector esta vacio para entrar en la excepcion
        std::vector<int> emptyData;
        Statistics<int> statsEmpty(emptyData);

    }
    //Debo indicar el tipo de error que el programa mostrara
    catch(const std::invalid_argument& e){
        std::cerr << "Exception encontrada: " << e.what() << std::endl;
    }
    
    return 0;
}







