# include <random>
# include <iostream>

void fill_array(double * array, int size, int seed, double mu, double sigma);
double get_mean(double * array, int size);

int main(void)
{
	const int N = 100000;
	const int seed = 1;
	double * data;

	data = new double [N]; /*Recordar que este en una asginacion de memoria heap la cual necesita implementar un delete para que devuelva la memoria utilizada. Tambien se podria utilizar la asignacion stack con: double data[N];  */

	fill_array(data, N, seed, 1.5, 0.5);
	std::cout<< "The mean is : " << get_mean(data, N) << std::endl;
	/*std::cout<< "The mean is : " << get_mean(data, N+1) << std::endl;*/
	/*Ya que get_mean recibe el array y el tamaño del array, no se puede usar N+1 porque al entrar a la funcion pediria el valor de un elemento que no existe*/

	/*Nueva linea*/ delete [] data; /*Para que no haya fuga de memoria*/

	return 0;
}

void fill_array(double * array, int size, int seed, double mu, double sigma)
{
	std::mt19937 gen(seed);
	std::normal_distribution<> dis{mu, sigma};

	for(int n = 0; n < size ; n++) 
	/*for(int n = 1; n >= 0; n++)*/
	/*Se quiere asignar un valor a cada espacio del arreglo, asi que debe empezar en 0 y terminar en size, sin que n=size*/
	{ 
		array[n] = dis(gen); 
		/*array[n++] = dis(gen);*/ 
		/*al final cada for hacia un n=n+2*/
	}
}

double get_mean(double * array, int size)
{
	double sum=0;
	/*double sum;*/
	/*Habia una fuga de memoria porque le estaba asignando cualquier valor a sum al no estar declarado*/

	for (int ii = 0; ii < size; ii++)
	/*for (int ii = 0; ii <= size; ii += 2)*/
	/*ii no puede ser igual a size porque estaria asignando un valor a un elemento del array que no existe, ademas se saltaba un elemento del array en cada ciclo*/
	{
		sum += array[ii];
		/*sum = array[ii];*/
		/*sum solo estaba guardando el dato del ultimo elemento del array en vez de sumarlos*/
	}

	/*array = new double [2];*/
	/*Se elimina esta linea ya que no es necesario cambiar el tamaño del array*/
	
	return sum/(1.0*size); 
	 /*return sum/size;*/
	 /*Se cambia a size de int a double*/
}
