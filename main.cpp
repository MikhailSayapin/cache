#include <iostream>
#include <chrono>


int main(){
    int *array;
    unsigned int capacity = 4096;
    const unsigned int MAX_CACHE_SIZE = 11796480;
    
    
    
    do{
        array=new int[capacity];
        for(unsigned int i=0;i<capacity;i++)
            array[i]=rand()%9;
        int t;
        
        
        
        //прямой обход
        auto timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;i++){
            for(unsigned int j=0;j<capacity;j++){
                t=array[j];  
            }
        }
        auto timer_of = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        std::cout <<"direct :"<< "(cache_size=" << (capacity*4)/1024 << ") (" << "time:" << diff << ") " << std::endl;

  
        
        //обратный обход
        timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;i++){
            for(unsigned int j=capacity-1; j!=0 ;j--){
                t=array[j];
            }
        }
        timer_of = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        std::cout <<"reverse :"<< "(cache_size=" << (capacity*4)/1024 << ") (" << "time:" << diff << ") " << std::endl;
       
     
        
        //случайный обход
        unsigned int capacity2=capacity;       
        timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;i++){
            while(capacity2 != 0){
                t=rand()%capacity2;
                std::swap(array[t],array[capacity2-1]);
                capacity2--;
            }
        }
        timer_of = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        std::cout <<"random :"<< "(cache_size=" << (capacity*4)/1024 << ") (" << "time:" << diff << ") " << std::endl;
        
        
        capacity*=2;
        if(capacity == MAX_CACHE_SIZE)
            capacity = MAX_CACHE_SIZE*3/2;
        delete[] array;    
    }while(capacity < MAX_CACHE_SIZE*3/2);
    
    
    
    
    return 0;
}
