//#include <windows.h>
//#include<iostream>
//#include <regex>
//
//#include"InitConnect.h"
//#include "Sha256.h"
//#pragma comment(lib, "ws2_32.lib")
//
//using namespace std;
//
//
//int prepare();
//
//HstConnect* hstConnect = new HstConnect();
//
//void recive() {
//	string message;
//	while (1) {
//		message = hstConnect->ReceiveMessage();
//		//std::cout << message << endl;
//		if (message[0] != 0) {
//			std::cout << message[0] << endl;
//		}
//	}
//}
//
//int main() {
//	if (prepare() < 0) {
//		return -1;
//	}
//
//	//��¼��ע��
//	char op;
//	std::cout << ">>>>> ���¼��ע��(��¼��1,ע����2):";
//	std::cin >> op;
//
//	if (op == '1') {
//		while (1) {
//			SetConsoleTitle("��¼");
//			char name[1024];
//			char password[1024];
//			std::cout << ">>> ��¼" << endl;
//			std::cout << ">>>>> �û���:";
//			std::cin >> name;
//			std::cout << ">>>>> ����:";
//			std::cin >> password;
//			
//			int l = hstConnect->Login(name, password);
//			if (l == 0) {
//				std::cout << "��¼�ɹ���" << endl;
//				break;
//			}
//			else {
//				std::cout << "��½ʧ�ܣ������˺����룡" << endl;
//			}
//		}
//	}
//	else if (op == '2') {
//		while (1) {
//			SetConsoleTitle("ע��");
//			char name[1024];
//			char password[1024];
//			std::cout << ">>>ע��" << endl;
//			std::cout << ">>>>>�û���:";
//			std::cin >> name;
//			std::cout << ">>>>>����(��֧��9~16 λ���ֺ���ĸ�����):";
//			std::cin >> password;
//
//			
//			regex repPattern("[0-9a-zA-Z]{9,16}", regex_constants::extended);
//
//			// ����ƥ��
//			bool bValid = regex_match(password, repPattern);
//
//			if (bValid)
//			{
//				// ƥ��ɹ�
//
//				char sha256[256];
//				Sha256* sha_hst = nullptr;
//				sha_hst->StrSHA256(password, sizeof(password) - 1, sha256);  // sizeof()������ĩβ����ֹ��'\0'�� -1
//
//				int r = hstConnect->Register(name, sha256);
//
//				if (r == 0) {
//					std::cout << "ע��ɹ���" << endl;
//					break;
//					
//				}
//				else {
//					std::cout << "ע��ʧ�ܣ��û����ѱ�ռ��" << endl;
//					
//				}
//			}
//			else
//			{
//				std::cout << "ע��ʧ�ܣ����������ʽ����" << endl;
//				std::cout << "�ٴν���ע��ҳ�棡" << endl;
//			}
//		}
//
//	}
//
//	std::cout << "��ѡ������1��ʼ������칦��ѡ��" << endl;
//	int choose;
//	std::cin >> choose;
//	getchar();
//
//	if (choose == 1)
//	{
//		// ����ѡ��
//		// ���죺����orȺ��
//		// ���ѣ����orɾ��
//		std::cout << "��ѡ��Ⱥ�Ļ��Ļ�����Ӻ��ѣ�Ⱥ��1������2���Ӻ���3��" << endl;
//		int choosenum;
//		std::cin >> choosenum;
//		getchar();
//
//		int c = hstConnect->ChoosePattern(choosenum);
//		if (c == 0)
//		{
//			std::cout << "ѡ��ɹ���" << endl;
//		}
//		else {
//			std::cout << "ѡ��ʧ�ܣ�" << endl;
//		}
//
//		//���շ�������Ϣ
//		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)recive, NULL, NULL, NULL);
//
//		if (choosenum == 1) {
//			SetConsoleTitle("Ⱥ�Ľ���");
//			std::cout << "����Ⱥ�Ľ���" << endl;
//			while (1) {
//				char message[1024];
//				gets_s(message);
//				int s = hstConnect->SendMessage(message);
//				if (s == 0) {
//					std::cout << "���ͳɹ���" << endl;
//				}
//				else {
//					std::cout << "����ʧ�ܣ�" << endl;
//				}
//			}
//		}
//
//		else if (choosenum == 2) {
//			SetConsoleTitle("���Ľ���");
//			std::cout << "���뵥�Ľ���" << endl;
//			string friendList;
//			friendList = hstConnect->ReceiveFriendList();
//			std::cout << "���ĺ����У�";
//			if (friendList[0])
//			{
//				std::cout << friendList << endl;
//			}
//
//			std::cout << "��ѡ���������";
//			int friendNum;
//			cin >> friendNum;
//			getchar();
//			int c = hstConnect->ChooseFriend(friendNum);
//			if (c == 0) {
//				std::cout << "ѡ��ɹ���" << endl;
//			}
//			else {
//				std::cout << "ѡ��ʧ�ܣ�" << endl;
//			}
//
//
//			//������Ϣ
//			while (1) {
//				char message[1024];
//				gets_s(message);
//				int s = hstConnect->SendMessage(message);
//				if (s == 0)
//				{
//					std::cout << "���ͳɹ���" << endl;
//				}
//				else
//				{
//					std::cout << "����ʧ�ܣ�" << endl;
//				}
//			}
//}
//		else if (choosenum == 3) {
//			cout << "tst";
//			SetConsoleTitle("��Ӻ���");
//
//			std::cout << "\n������Ҫ��ӵ��û���";
//
//
//			char addName[1024];
//			gets_s(addName);
//
//			int c = hstConnect->AddFriend(addName);
//
//			system("pause");
//
//			if (c == 0) {
//				std::cout << "����ѡ��ɹ���" << endl;
//			}
//			else {
//				std::cout << "����ѡ��ʧ�ܣ�" << endl;
//			}
//			system("pause");
//		}
//	return 0;
//}
//
//
//}
//
//
