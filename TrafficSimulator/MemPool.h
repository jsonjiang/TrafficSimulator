#pragma once
#include <vector>
#include <list>
#include <bitset>

#define PAGE_SIZE 64
template <class T>
class CMemPool
{
public:
	CMemPool(){m_vecArray.push_back(new T[PAGE_SIZE]);}
	T* Alloc(){
		std::list<std::bitset<PAGE_SIZE>*>::iterator it = m_poolRecord.begin();
		int index = 0;
		for (;it!=m_poolRecord.end();it++){
			std::bitset<PAGE_SIZE>* poolRecord = *it;
			if (!poolRecord->all()){
				for(int i=0;i<PAGE_SIZE;++i){
					if (poolRecord[i] == 0){
						poolRecord[i] = 1;
						return m_vecArray[index]+i;
					}
				}
			}
			else{
				++index;
			}
		}
		//没有空间了
		m_vecArray.push_back(new T[PAGE_SIZE]);
		m_poolRecord.push_back(new std::bitset<PAGE_SIZE>(0x1));
		return m_vecArray.back();
	}
    void Release(T* pObj){
        std::list<std::bitset<PAGE_SIZE>*>::iterator it = m_poolRecord.begin();
        int index = 0;
        for (;it!=m_poolRecord.end();it++){
            std::bitset<PAGE_SIZE>* poolRecord = *it;
            T* pArray = m_vecArray[index];
            if (pObj > pArray && pObj < pArray + PAGE_SIZE){
                poolRecord[pObj - pArray] = 0;
                return;
            }
        }
        //throw CExption
    }
	~CMemPool(){
		std::list<std::bitset<PAGE_SIZE>*>::iterator itRecord = m_poolRecord.begin();
		for (;itRecord!=m_poolRecord.end();++itRecord){
			delete *itRecord;
		}
		m_poolRecord.clear();
		std::vector<T*>::iterator it = m_vecArray.begin();
		for (;it!=m_vecArray.end();it++){
			delete *it;
		}
		m_vecArray.clear();
	}
private:
	std::vector<T*> m_vecArray;
	std::list<std::bitset<PAGE_SIZE>*> m_poolRecord;
};