def show_menu():                    # visar menyn för användare
    print('=== NÄTVERKSVERKTYG ===')
    print('1. Validera IP-adress')
    print('2. Validera port')
    print('3. Visa logg')
    print('4. Avsluta.')

def validate_ip(ip):
     ip = ip.strip()                # tar bort mellanslag i början/slutet
     octets = ip.split(".")         # delar upp strängen vid varje punkt
     if len(octets) != 4: 
          return False              # om det inte är exakt 4 delar: avslutar funktionen och ger "ogiltig IP" 
     for octet in octets:           # loopar igenom varje del
          if not octet.isdigit(): 
               return False         # om det inte är siffror: avslutar funktionen och ger "ogiltig IP"
     if not 0 <= int(octet) <= 255:
              return False #       # om det är utanför intervallet: avslutar funktionen och ger "ogiltig IP"
     return True                   # om allt ovan klaras: Giltig IP! 

def validate_port(port):
     port = port.strip()

     if not port.isdigit():
          return False
     
     port = int(port)

     if 1 <= port <= 65535:
          return True
     else:
          return False
     
while True: 
     show_menu()
     choice = input('Gör ett val (1-4): ')
         
     if choice == '1': 
          ip = input('Ange IP-adress: ')
          if validate_ip(ip):
               print(f'{ip} är en giltig IP-adress. \n')
          else:
               print(f'{ip} är en ogiltig IP-adress. \n')
               
     elif choice == '2':
          port = input('Ange port: ')
          if validate_port(port):
               print(f'Port {port}' ' är giltig!')  
          else:
               print(f'Port {port} är ogiltig.')  
                              
          import logging
          logging.basicConfig(
          level=logging.INFO,
          format='%(asctime)s - %(levelname)s - %(message)s',
          datefmt='%Y-%m-%d %H:%M:%S')                         
          logg = []
                              
     if choice == '3':
          print('Logg:')
          for rad in logg:
               print(rad)
     elif choice == '4': 
          print('Avslutar...')
          break 
                              
    