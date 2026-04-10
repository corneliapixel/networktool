def show_menu():                    # visar menyn för användare
    print('=== NÄTVERKSVERKTYG ===')
    print('1. Validera IP-adress')
    print('2. Validera port')
    print('3. Visa logg')
    print('4. Avsluta.\n')

def validate_ip(ip):
    ip = ip.strip()                 # tar bort mellanslag i början/slutet
    octets = ip.split(".")          # delar upp strängen vid varje punkt
    
    if len(octets) != 4:
        return False                # om det inte är exakt 4 delar: avslutar funktionen och ger "ogiltig IP" 
    
    for octet in octets:            # loopar igenom varje del
        if not octet.isdigit(): 
            return False            # om det inte är siffror: avslutar funktionen och ger "ogiltig IP"
        if not 0 <= int(octet) <= 255:
            return False #          # om det är utanför intervallet: avslutar funktionen och ger "ogiltig IP"
         
    return True                     # om allt ovan klaras: Giltig IP! 


def validate_port(port):
    port = port.strip()
    
    if not port.isdigit():
        return False
    
    port = int(port)
    
    if 1 <= port <= 65535:
        return True
    else:
        return False


def show_log(log):
    print('\t=== LOGGEN ===')

    if len(log) == 0:
        print('\t Loggen är tom. \n')
    else:
         for index, entry in enumerate(log, start=1):
             print(f'{index}\t{entry}')


def main():
    log = []                       # här ligger logglistan
    
    while True: 
         show_menu()
         choice = input('Gör ett val (1-4): ')
     
         if choice == '1': 
             while True: 
                 ip = input('Ange IP-adress: ')
                 if validate_ip(ip):
                     print(f'{ip} är en giltig IP-adress. \n')
                     log.append(f'IP {ip} - giltig')
                     break 
                 else:
                     print(f'"{ip}" är en ogiltig IP-adress. Försök igen! \n')
                     log.append(f'IP "{ip}" - ogiltig')
             
         elif choice == '2':
             while True:
                port = input('Ange port: ')
                  
                if validate_port(port):
                     print(f'Port {port} är giltig!\n')
                     log.append(f'Port {port} - giltig')
                     break
                else:
                      print(f'Port "{port}" är ogiltig. Försök igen,\nkom igen då? xD \n')
                      log.append(f'Port "{port}" - ogiltig')
                    
         elif choice == '3':
             show_log(log)
             print()
     
         elif choice == '4':
            print(f'Antal valideringar: {len(log)}\n')
            print('Avslutar...\n')
            break
         
         else: 
             print(f'Ogiltigt val, försök igen.\n')
main()
