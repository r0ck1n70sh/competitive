#include <bits/stdc++.h>
using namespace std;
const int maxl=1e6+3;
class lib{
	public:
	int no_of_books, signup_time, books_per_day, id;
	vector<int> lib_book;
	
	lib(int id, int no_of_books, int signup_time, int books_per_day){
		this->id= id;
		this->no_of_books= no_of_books;
		this->signup_time= signup_time;
		this->books_per_day= books_per_day;
		this->lib_book.resize(no_of_books);
	}
};

vector<lib> libs;
vector<int> book_id, vis_book;
int total_book, total_lib, total_day;

bool comp_lib(lib a, lib b){
	return a.no_of_books*a.books_per_day > b.no_of_books*b.books_per_day;
}

bool comp_book(int a, int b){
	return book_id[a] > book_id[b];
}

int main(){
	freopen("in/f.txt", "r",stdin);
	freopen("out/f.txt","w",stdout);
	
	cin>>total_book>>total_lib>>total_day;
	book_id.resize(total_book);
	vis_book.resize(total_book, 0);
	
	for(int i=0,s;i<total_book;i++) {
		cin>>s; book_id[i]=s;
	}
	
 	for(int i=0;i<total_lib;i++){
		int no_of_books, signup_time, books_per_day;
		cin>>no_of_books>>signup_time>>books_per_day;
		
		libs.push_back(lib(i, no_of_books, signup_time, books_per_day));
		
		for(int j=0;j<libs[i].no_of_books;j++)
			cin>>libs[i].lib_book[j];
	}
	
	//cout<<"input done!\n";
	//print();
	
	sort(libs.begin(), libs.end(), comp_lib);
	//cout<<"sorting done!\n";
	
	int days_left=total_day, libs_needed=0;
	
	for(int idx=0;idx<total_lib;idx++){
		if(libs[idx].signup_time>days_left) continue;
		days_left-=libs[idx].signup_time;
		libs_needed++;
	}
	
	cout<<libs_needed<<"\n";
	days_left= total_day;
	
	for(int idx=0;idx<total_lib;idx++){
		if(libs[idx].signup_time>days_left) continue;
		days_left-=libs[idx].signup_time;
		sort(libs[idx].lib_book.begin(),libs[idx].lib_book.end(),comp_book);
		
		vector<int> books;
		int max_size= libs[idx].no_of_books*days_left;
		 
		for(int i=0;i<libs[idx].no_of_books;i++){
			if(vis_book[libs[idx].lib_book[i]]) continue;
			vis_book[libs[idx].lib_book[i]]=1;
			
			if(int(books.size())>max_size) break; 
			books.push_back(libs[idx].lib_book[i]);
		}
		
		if(books.empty()){
			cout<<libs[idx].id<<" 1\n";
			cout<<libs[idx].lib_book[0]<<"\n";
			continue;
		}

		cout<<libs[idx].id<<" "<<books.size()<<"\n";
				
		for(int i=0;i<int(books.size());i++) cout<<books[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
