#pragma once

#include <iostream>
#include "clsDate.h"
#include "queue"
#include "stack"

using namespace std;


class clsQueueLine {
private:
    string _name_of_tickets;
    int _the_average_min;
    short _TotalTickets = 0;
    short _AverageServeTime = 0;
    string _Prefix = "";
    class clsTicket {
        private:
            short _Number = 0;
            string _Prefix;
            string _TicketTime;
            short _WaitingClients = 0;
            short _AverageServeTime = 0;
            short _ExpectedServeTime = 0;
        public:
            clsTicket(string Prefix, short Number,
                    short WaitingClients, short AverageServeTime) {
                _Number = Number;
                _TicketTime = clsDate::GetSystemDateTimeString();    
                _Prefix =  Prefix;
                _WaitingClients = WaitingClients;
                _AverageServeTime = AverageServeTime;

            }
            string Prefix() {
                return _Prefix;
            }
            short Number() {
                return _Number;
            }
            string FullNumber() {
                return _Prefix + to_string(_Number);
            }
            string TicketTime() {
                return _TicketTime;
            }
            short WaitingClients () {
                return _WaitingClients;
            }
            short ExpectedServeTime() {
                return _AverageServeTime * _WaitingClients;
            }
            void print () {
                cout << "\n";
                cout << "========================================\n";
                cout << "               TICKET INFO              \n";
                cout << "========================================\n";
                cout << " Ticket Number      : " << FullNumber() << "\n";
                cout << " Issue Time         : " << _TicketTime << "\n";
                cout << " Waiting Clients    : " << _WaitingClients << "\n";
                cout << " Avg Serve Time     : " << _AverageServeTime << " Min\n";
                cout << " Expected Wait Time : " << ExpectedServeTime() << " Min\n";
                cout << "========================================\n";
                cout << "\n";
            }
        };
public:
    queue <clsTicket> QueueLine;
    clsQueueLine(string Prefix, short AverageServeTime) {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _AverageServeTime = AverageServeTime;
    }
    void IssueTicket() {
        _TotalTickets++;
        clsTicket Ticket(_Prefix, _TotalTickets, WaitingClinets(), _AverageServeTime);
        QueueLine.push(Ticket);
    }
    int WaitingClinets() {
        return QueueLine.size();
    }

    string WhoIsNext() {
        if(QueueLine.empty()){
            return "No Clients Left.";
        }
        else
            return QueueLine.front().FullNumber();
    }
    bool ServeNextClient() {
        if(QueueLine.empty())
            return false;
        QueueLine.pop();
        return true;
    }

    short ServedClients() {
        return _TotalTickets - QueueLine.size();
    }
    void PrintInfo() {
        cout << "\n";
        cout << "========================================\n";
        cout << "               Queue Line               \n";
        cout << "========================================\n";
        cout << " Prefix            : " << _Prefix << "\n";
        cout << " Total Tickets      : " << _TotalTickets << "\n";
        cout << " Waiting Clients    : " << WaitingClinets() << "\n";
        cout << " Served Clients     : " << ServedClients() << "\n";
        cout << " Average Serve Time : " << _AverageServeTime << " Min\n";
        cout << "----------------------------------------\n";

        cout << " Status             : ";
        if (QueueLine.empty())
            cout << "No Clients Left.\n";
        else
            cout << "Clients are waiting.\n";

        cout << "========================================\n";
        cout << "\n";
    }
    void PrintTicketsLineRTL(){
        if (QueueLine.empty()) {
            cout << "\n\t\t Tickets: No Tickets.";
        }
        else {
            cout << "\n\t\t Tickets: ";

        }
        // we copy the queue in order not to lose the original 
        queue <clsTicket> TempQueueLine = QueueLine;
        while(!TempQueueLine.empty()) {
            clsTicket Ticket = TempQueueLine.front();
            cout << " " << Ticket.FullNumber() <<  " <-- ";
            TempQueueLine.pop();
        }
        cout << "\n";
    }
    void PrintTicketsLineLTR(){
        if (QueueLine.empty()) {
            cout << "\n\t\t Tickets: No Tickets.";
        }
        else {
            cout << "\n\t\t Tickets: ";

        }
        // we copy the queue in order not to lose the original 
        queue <clsTicket> TempQueueLine = QueueLine;
        stack <clsTicket> TempStackLine;
        while(!TempQueueLine.empty()) {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }
        while (!TempStackLine.empty()) {
            clsTicket Ticket = TempStackLine.top();
            cout << " " << Ticket.FullNumber() <<  " --> ";
            TempStackLine.pop();
        }
        
        cout << "\n";
    }
    void PrintAllTickets() {
        cout << "\n";
        cout << "========================================\n";
        cout << "              ALL TICKETS               \n";
        cout << "========================================\n";

        if (QueueLine.empty()) {
            cout << " No tickets in the queue.\n";
            cout << "========================================\n";
            cout << "\n";
            return;
        }

        cout << " Total Tickets : " << _TotalTickets << "\n";
        cout << " Waiting       : " << WaitingClinets() << "\n";
        cout << " Served        : " << ServedClients() << "\n";
        cout << "----------------------------------------\n";

        queue<clsTicket> TempQueueLine = QueueLine;
        short Index = 1;

        while (!TempQueueLine.empty()) {
            cout << " Ticket #" << Index++ << "\n";
            TempQueueLine.front().print();
            TempQueueLine.pop();
        }

        cout << "========================================\n";
        cout << "\n";
    }

};

