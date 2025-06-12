#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

// 현 답안에서는 조건 중 array의 원소 < 1000이 없다고 가정
// 즉, 원소가 0 보다 크다고만 가정했기 때문에, HashMap을 구현
// + 해시맵 공부
// 해시 맵의 초기 크기(소수로 지정)
#define INITIAL_HASH_SIZE 503
#define THRESHOLD 0.75f

// HashMap을 구현하기 위한 구조체
// 노드
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;
// 해시 맵
typedef struct HashMap {
    HashNode** buckets;
    int size;
    int num_of_elements;
} HashMap;

// 해시 맵 초기화
HashMap* createHashMap() {
    // 맵 포인터 할당
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    if (map == NULL) {
        perror("HashMap malloc error");
        return NULL;
    }
    // 초기화
    map->size = INITIAL_HASH_SIZE;
    map->num_of_elements = 0;
    // 버킷 할당(calloc이므로 내부는 NULL로 초기화)
    map->buckets = (HashNode**)calloc(INITIAL_HASH_SIZE, sizeof(HashNode**));
    if (map->buckets == NULL) {
        perror("HashMap bucket calloc error");
        free(map);
        return NULL;
    }
    return map;
}

// 해시 함수
unsigned int hash (int key, int map_size) {
    // 간단하게 구현
    return (unsigned int)abs(key) % map_size;
}

// 해시 맵 메모리 해제
int freeHashMap(HashMap* map) {
    if (map == NULL) return 1;
    
    // 각 버킷 내의 해시 노드 메모리 해제
    for (int i = 0; i < map->size; i++) {
        HashNode* current = map->buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    // 버킷 메모리 해제
    free(map->buckets);
    // 맵 메모리 해제
    free(map);
}

// 해시 맵 리사이징
bool resizeHashMap(HashMap* map, int new_size) {
    // 새 크기 validation
    if (new_size < map->num_of_elements || new_size <= 0) {
        return false;
    }
    
    // 새 버킷 배열 할당 및 초기화
    HashNode **new_buckets = (HashNode**)calloc(new_size, sizeof(HashNode*));
    if(new_buckets == NULL) {
        perror("New buckets calloc error");
        return false;
    }
    
    // 기존 노드를 새 버킷에 재해싱
    for (int i = 0; i < map->size; i++) {
        HashNode* current = map-> buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            
            // 인덱스 재계산(재해싱)
            unsigned int new_index = hash(temp->key, new_size);
            
            // 제일 앞에 추가
            temp->next = new_buckets[new_index];
            new_buckets[new_index] = temp;
        }
    }
    // 이전 버킷 해제
    free(map->buckets);
    
    // map attribute 업데이트
    map->buckets = new_buckets;
    map->size = new_size;
    
    return true;
}

// 소수인지 확인
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 소수를 얻는 함수(해시맵의 크기는 소수로 함.)
int get_prime(int num) {
    if (num <= 2) return 2;
    int prime = num;
    while(1) {
        if (is_prime(prime)) return prime;
        prime++;
    }
}

// 검색 동작
HashNode* find_node(HashMap* map, int key) {
    // insert를 대비해 리사이징 확인
    if ((float)map->num_of_elements / map->size > THRESHOLD) {
        int new_size = get_prime(map->size * 2); //2배 증가
        if (!resizeHashMap(map, new_size)) return NULL;
    }
    
    // 인덱스 계산 및 탐색 시작 위치.
    unsigned int index = hash(key, map->size);
    // 해시 값을 이용하기 때문에 탐색할 노드의 수가 적음
    HashNode* current = map->buckets[index];
    
    // 탐색하며 조건에 맞으면 해당 노드 포인터를 return
    while (current != NULL) {
        if (current->key == key) return current;
        current = current->next;
    }
    
    // 키가 없음
    // 새 노드
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    if(new_node == NULL) {
        perror("HashNode malloc error");
        return NULL;
    }
    // 값 할당 및 제일 앞에 삽입
    new_node->key = key;
    new_node->value = 0;
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
    
    return new_node;
}


// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    if (array_len == 0) return -1;
    if (array_len == 1) return array[0];
    
    // 해시 맵 생성
    HashMap* counts = createHashMap();
    if (counts == NULL) return 0;
    
    // counting
    for (int i = 0; i < array_len; i++) {
        HashNode* node = find_node(counts, array[i]);
        if (node == NULL) {
            freeHashMap(counts);
            return 0;
        }
        node->value++;
    }
    
    // 초기값 할당
    int answer = -1;
    int max_value = 0;
    
    // 최빈값 탐색 (모든 노드를 탐색 for-while 이지만 선형 탐색);
    for (int i = 0; i < counts->size; i++) {
        HashNode* current = counts->buckets[i];
        while (current != NULL) {
            if (current->value == max_value) answer = -1;
            if (current->value > max_value) {
                max_value = current->value;
                answer = current->key;
            }
            current = current->next;
        }
    }
    
    // 해시맵 메모리 해제
    freeHashMap(counts);
    
    return answer;
}