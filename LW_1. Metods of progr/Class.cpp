#include"Class.h"

void initList(String **Head)
{
	(*Head) = NULL;
}

void initList(StrNum **Head)
{
	(*Head) = NULL;
}

void AddElem(String **Head, String *elem, int q)
{
	initList(&(elem->pH));
	StrNum *tp = new StrNum;
	tp->Data = q;
	tp->next = elem->pH;
	elem->pH = tp;
	String *tmp = elem;
	tmp->next = *Head;
	*Head = tmp;
}

void AddElemNum(StrNum **Head, int q)
{
	StrNum *tp = new StrNum;
	tp->Data = q;
	tp->next = *Head;
	*Head = tp;
}

bool Find(String *Head, char *s, int t, int q){
	if (Head == NULL) return 0;
	String *Now = Head;
	while (Now != NULL){
		if (strcmp(Now->Str, s) == 0){
			if (t == 1){
				Now->Nom1++;
			}
			else{
				Now->Nom2++;
			}
			AddElemNum(&(Now->pH), q);
			return 1;
		}
		Now = Now->next;
	}
	return 0;
}

bool check(String *Head){
	int che = 0;
	String *Now = Head;
	while (Now != NULL){
		StrNum *Now1 = Now->pH;
		if (Now->Nom1 != 0 && Now->Nom2 == 0){
			for (Now1; Now1 != NULL; Now1 = Now1->next){
				cout << "FILE 1, string " << Now1->Data << ": " << Now->Str << endl;
				che++;
			}
		}
		else if (Now->Nom2 != 0 && Now->Nom1 == 0){
			for (Now1; Now1 != NULL; Now1 = Now1->next){
				cout << "FILE 2, string " << Now1->Data << ": " << Now->Str << endl;
				che++;
			}
			int k = 0;
		}
		Now = Now->next;
	}
	if (che == 0){
		cout << "There are no such rows" << endl;
	}
	return true;
}

int freeList(String ** Head) {
	String * current;
	StrNum * curr;
	while (*Head != NULL) {
		current = *Head;
		*Head = current->next;
		free(current->Str);
		if (*Head != NULL){
			while ((*Head)->pH->next != NULL && (*Head)->pH){
				curr = (*Head)->pH;
				(*Head)->pH = curr->next;
				delete curr;
			}
		}
		delete current;
	};

	return 0;
}
