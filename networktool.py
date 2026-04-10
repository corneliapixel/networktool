def show_menu():                    # visar menyn för användaren
    print('=== NÄTVERKSVERKTYG ===')
    print('1. Validera IP-adress')
    print('2. Validera port')
    print('3. Visa logg')
    print('4. Avsluta.\n')

def validate_ip(ip):                # validera IP-adress
    ip = ip.strip()                 # ta bort mellanslag i början/slutet
    octets = ip.split(".")          # dela upp strängen vid varje punkt
    
    if len(octets) != 4:
        return False                # om det inte är exakt 4 delar: avsluta funktionen och returnera "ogiltig IP" 
    
    for octet in octets:            # loopar igenom varje del
        if not octet.isdigit(): 
            return False            # om det inte är siffror: avsluta funktionen och returnera "ogiltig IP"
        if not 0 <= int(octet) <= 255:
            return False            # om det är utanför intervallet: avsluta funktionen och returnera "ogiltig IP"
         
    return True                     # om allt ovan klaras: "giltig IP"! 


def validate_port(port):            # validera port 
    port = port.strip()             # ta bort mellanslag i början/slutet
    
    if not port.isdigit():          
        return False                # om det inte är siffror: avslutar funktionen och returnerar "ogiltig port"
    
    port = int(port)                # port = integrer (heltal)
    
    if 1 <= port <= 65535:          # om intervallet är: 
        return True                 # innanför, returnera "giltig port"
    else:
        return False                # utanför, returnera "ogiltig port"


def show_log(log):                  # visa loggen 
    print('\t=== LOGGEN ===')

    if len(log) == 0:               # om loggen = 0
        print('\t Loggen är tom. \n')
    else:
         for index, entry in enumerate(log, start=1):       # loopar igenom loggen med numrering från 1
             print(f'{index}\t{entry}')                     # skriver ut index och loggrad


def main():
    log = []                       # här ligger logglistan
    
    while True: 
         show_menu()
         choice = input('Gör ett val (1-4): ').strip()
     
         if choice == '1':
             # validera IP-adress
             while True: 
                 ip = input('Ange IP-adress: ').strip()
                 if validate_ip(ip):
                     print(f'{ip} är en giltig IP-adress. \n')
                     log.append(f'IP {ip} - giltig')
                     break 
                 else:
                     print(f'"{ip}" är en ogiltig IP-adress. Försök igen! \n')
                     log.append(f'IP "{ip}" - ogiltig')
             
         elif choice == '2':
             # validera port
             while True:
                port = input('Ange port: ').strip()
                  
                if validate_port(port):
                     print(f'Port {port} är giltig!\n')
                     log.append(f'Port {port} - giltig')
                     break
                else:
                      print(f'Port "{port}" är ogiltig. Försök igen,\nkom igen då? xD \n')
                      log.append(f'Port "{port}" - ogiltig')
                    
         elif choice == '3':
             # visa loggen
             show_log(log)
             print()
     
         elif choice == '4':
             # avsluta programmet
             print(f'Antal valideringar: {len(log)}\n')
             print('Avslutar...\n')
             break
         
         else: 
             print(f'Ogiltigt val, försök igen.\n')
main()
