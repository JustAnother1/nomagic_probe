#!/usr/bin/python3
# -*- coding: utf-8 -*-

import PySimpleGUI as sg




layout = [[sg.Text('hex : '), sg.Input(default_text = '0x00000000', size= (10, 1), key='-INPUT-'), sg.Button('hex -> bin', key='-hex2bin-')],
          [sg.Text('bin : 0000 0000  0000 0000  0000 0000  0000 0000', key='-BINARY-')],
          [ sg.Button('31', button_color='white on gray', key='-31-'),
            sg.Button('30', button_color='white on gray', key='-30-'),
            sg.Button('29', button_color='white on gray', key='-29-'),
            sg.Button('28', button_color='white on gray', key='-28-'),            
            sg.Button('27', button_color='white on gray', key='-27-'),
            sg.Button('26', button_color='white on gray', key='-26-'),
            sg.Button('25', button_color='white on gray', key='-25-'),
            sg.Button('24', button_color='white on gray', key='-24-'),
            sg.Button('23', button_color='white on gray', key='-23-'),
            sg.Button('22', button_color='white on gray', key='-22-'),
            sg.Button('21', button_color='white on gray', key='-21-'),
            sg.Button('20', button_color='white on gray', key='-20-'),
            sg.Button('19', button_color='white on gray', key='-19-'),
            sg.Button('18', button_color='white on gray', key='-18-'),
            sg.Button('17', button_color='white on gray', key='-17-'),
            sg.Button('16', button_color='white on gray', key='-16-'),
            sg.Button('15', button_color='white on gray', key='-15-'),
            sg.Button('14', button_color='white on gray', key='-14-'),
            sg.Button('13', button_color='white on gray', key='-13-'),
            sg.Button('12', button_color='white on gray', key='-12-'),
            sg.Button('11', button_color='white on gray', key='-11-'),
            sg.Button('10', button_color='white on gray', key='-10-'),
            sg.Button('9', button_color='white on gray', key='-9-'),
            sg.Button('8', button_color='white on gray', key='-8-'),
            sg.Button('7', button_color='white on gray', key='-7-'),
            sg.Button('6', button_color='white on gray', key='-6-'),
            sg.Button('5', button_color='white on gray', key='-5-'),
            sg.Button('4', button_color='white on gray', key='-4-'),
            sg.Button('3', button_color='white on gray', key='-3-'),
            sg.Button('2', button_color='white on gray', key='-2-'),
            sg.Button('1', button_color='white on gray', key='-1-'),
            sg.Button('0', button_color='white on gray', key='-0-'),
          ],
         [sg.Button('Exit')]]

window = sg.Window('Bit Bang', layout)

data = {}

def invalidate_data():
    data['0'] = False
    data['1'] = False
    data['2'] = False
    data['3'] = False
    data['4'] = False
    data['5'] = False
    data['6'] = False
    data['7'] = False
    data['8'] = False
    data['9'] = False
    data['10'] = False
    data['11'] = False
    data['12'] = False
    data['13'] = False
    data['14'] = False
    data['15'] = False
    data['16'] = False
    data['17'] = False
    data['18'] = False
    data['19'] = False
    data['20'] = False
    data['21'] = False
    data['22'] = False
    data['23'] = False
    data['24'] = False
    data['25'] = False
    data['26'] = False
    data['27'] = False
    data['28'] = False
    data['29'] = False
    data['30'] = False
    data['31'] = False

def update_from_hex_char( val, offset):
    if val == '0':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = False
        data[str(1 + offset)] = False
        data[str(0 + offset)] = False
    elif val == '1':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = False
        data[str(1 + offset)] = False
        data[str(0 + offset)] = True
    elif val == '2':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = False
        data[str(1 + offset)] = True
        data[str(0 + offset)] = False
    elif val == '3':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = False
        data[str(1 + offset)] = True
        data[str(0 + offset)] = True
    elif val == '4':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = True
        data[str(1 + offset)] = False
        data[str(0 + offset)] = False
    elif val == '5':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = True
        data[str(1 + offset)] = False
        data[str(0 + offset)] = True
    elif val == '6':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = True
        data[str(1 + offset)] = True
        data[str(0 + offset)] = False
    elif val == '7':
        data[str(3 + offset)] = False
        data[str(2 + offset)] = True
        data[str(1 + offset)] = True
        data[str(0 + offset)] = True
    elif val == '8':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = False
        data[str(1 + offset)] = False
        data[str(0 + offset)] = False
    elif val == '9':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = False
        data[str(1 + offset)] = False
        data[str(0 + offset)] = True
    elif val == 'a' or val == 'A':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = False
        data[str(1 + offset)] = True
        data[str(0 + offset)] = False
    elif val == 'b' or val == 'B':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = False
        data[str(1 + offset)] = True
        data[str(0 + offset)] = True
    elif val == 'c' or val == 'C':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = True
        data[str(1 + offset)] = False
        data[str(0 + offset)] = False
    elif val == 'd' or val == 'D':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = True
        data[str(1 + offset)] = False
        data[str(0 + offset)] = True
    elif val == 'e' or val == 'E':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = True
        data[str(1 + offset)] = True
        data[str(0 + offset)] = False
    elif val == 'f' or val == 'F':
        data[str(3 + offset)] = True
        data[str(2 + offset)] = True
        data[str(1 + offset)] = True
        data[str(0 + offset)] = True       

def parseHex(hexStr):
    if (hexStr[0] != '0') or (hexStr[1] != 'x'):
        invalidate_data()
    else:
       update_from_hex_char(hexStr[2], 28)
       update_from_hex_char(hexStr[3], 24)
       update_from_hex_char(hexStr[4], 20)
       update_from_hex_char(hexStr[5], 16)
       update_from_hex_char(hexStr[6], 12)
       update_from_hex_char(hexStr[7], 8)
       update_from_hex_char(hexStr[8], 4)
       update_from_hex_char(hexStr[9], 0)
       

def update_data():
    update_bit_butons()
    update_binary()
    update_hex()
    
def update_hex():
    global data
    global window
    res = '0x'
    val = 0
    if True == data['31']:
        val = val + 8
    if True == data['30']:
        val = val + 4
    if True == data['29']:
        val = val + 2
    if True == data['28']:
        val = val + 1
    res = res + "%0.1X" % val
    
    val = 0
    if True == data['27']:
        val = val + 8
    if True == data['26']:
        val = val + 4
    if True == data['25']:
        val = val + 2
    if True == data['24']:
        val = val + 1
    res = res + "%0.1X" % val

    val = 0
    if True == data['23']:
        val = val + 8
    if True == data['22']:
        val = val + 4
    if True == data['21']:
        val = val + 2
    if True == data['20']:
        val = val + 1
    res = res + "%0.1X" % val

    val = 0
    if True == data['19']:
        val = val + 8
    if True == data['18']:
        val = val + 4
    if True == data['17']:
        val = val + 2
    if True == data['16']:
        val = val + 1
    res = res + "%0.1X" % val
    
    val = 0
    if True == data['15']:
        val = val + 8
    if True == data['14']:
        val = val + 4
    if True == data['13']:
        val = val + 2
    if True == data['12']:
        val = val + 1
    res = res + "%0.1X" % val    

    val = 0
    if True == data['11']:
        val = val + 8
    if True == data['10']:
        val = val + 4
    if True == data['9']:
        val = val + 2
    if True == data['8']:
        val = val + 1
    res = res + "%0.1X" % val  

    val = 0
    if True == data['7']:
        val = val + 8
    if True == data['6']:
        val = val + 4
    if True == data['5']:
        val = val + 2
    if True == data['4']:
        val = val + 1
    res = res + "%0.1X" % val  
    
    val = 0
    if True == data['3']:
        val = val + 8
    if True == data['2']:
        val = val + 4
    if True == data['1']:
        val = val + 2
    if True == data['0']:
        val = val + 1
    res = res + "%0.1X" % val  
    window['-INPUT-'].update(res)    

def update_binary():
    global data
    global window
    res = 'bin : '
    if True == data['31']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['30']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['29']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['28']:
        res = res + '1'
    else:
        res = res + '0'    
    
    res = res + ' '
    
    if True == data['27']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['26']:
        res = res + '1'
    else:
        res = res + '0' 
    if True == data['25']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['24']:
        res = res + '1'
    else:
        res = res + '0' 
        
    res = res + '  '
    
    if True == data['23']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['22']:
        res = res + '1'
    else:
        res = res + '0' 
    if True == data['21']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['20']:
        res = res + '1'
    else:
        res = res + '0'
        
    res = res + ' '
    
    if True == data['19']:
        res = res + '1'
    else:
        res = res + '0' 
    if True == data['18']:
        res = res + '1'
    else:
        res = res + '0' 
    if True == data['17']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['16']:
        res = res + '1'
    else:
        res = res + '0'  
    
    res = res + '  '
    
    if True == data['15']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['14']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['13']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['12']:
        res = res + '1'
    else:
        res = res + '0'
    
    res = res + ' '
    
    if True == data['11']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['10']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['9']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['8']:
        res = res + '1'
    else:
        res = res + '0'
    
    res = res + '  '
    
    if True == data['7']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['6']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['5']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['4']:
        res = res + '1'
    else:
        res = res + '0'
    
    res = res + ' '
    
    if True == data['3']:
        res = res + '1'
    else:
        res = res + '0'  
    if True == data['2']:
        res = res + '1'
    else:
        res = res + '0' 
    if True == data['1']:
        res = res + '1'
    else:
        res = res + '0'
    if True == data['0']:
        res = res + '1'
    else:
        res = res + '0'
    window['-BINARY-'].update(res)    
        
def update_bit_butons():
    global data
    if True == data['0']:
        window['-0-'].update( button_color='white on green')
    else:
        window['-0-'].update( button_color='white on gray')   
    if True == data['1']:
        window['-1-'].update( button_color='white on green')
    else:
        window['-1-'].update( button_color='white on gray')  
    if True == data['2']:
        window['-2-'].update( button_color='white on green')
    else:
        window['-2-'].update( button_color='white on gray')  
    if True == data['3']:
        window['-3-'].update( button_color='white on green')
    else:
        window['-3-'].update( button_color='white on gray')         
    if True == data['4']:
        window['-4-'].update( button_color='white on green')
    else:
        window['-4-'].update( button_color='white on gray')   
    if True == data['5']:
        window['-5-'].update( button_color='white on green')
    else:
        window['-5-'].update( button_color='white on gray')  
    if True == data['6']:
        window['-6-'].update( button_color='white on green')
    else:
        window['-6-'].update( button_color='white on gray')  
    if True == data['7']:
        window['-7-'].update( button_color='white on green')
    else:
        window['-7-'].update( button_color='white on gray')   
    if True == data['8']:
        window['-8-'].update( button_color='white on green')
    else:
        window['-8-'].update( button_color='white on gray')   
    if True == data['9']:
        window['-9-'].update( button_color='white on green')
    else:
        window['-9-'].update( button_color='white on gray')  
    if True == data['10']:
        window['-10-'].update( button_color='white on green')
    else:
        window['-10-'].update( button_color='white on gray')  
    if True == data['11']:
        window['-11-'].update( button_color='white on green')
    else:
        window['-11-'].update( button_color='white on gray')   
    if True == data['12']:
        window['-12-'].update( button_color='white on green')
    else:
        window['-12-'].update( button_color='white on gray')   
    if True == data['13']:
        window['-13-'].update( button_color='white on green')
    else:
        window['-13-'].update( button_color='white on gray')  
    if True == data['14']:
        window['-14-'].update( button_color='white on green')
    else:
        window['-14-'].update( button_color='white on gray')  
    if True == data['15']:
        window['-15-'].update( button_color='white on green')
    else:
        window['-15-'].update( button_color='white on gray')   
    if True == data['16']:
        window['-16-'].update( button_color='white on green')
    else:
        window['-16-'].update( button_color='white on gray')   
    if True == data['17']:
        window['-17-'].update( button_color='white on green')
    else:
        window['-17-'].update( button_color='white on gray')  
    if True == data['18']:
        window['-18-'].update( button_color='white on green')
    else:
        window['-18-'].update( button_color='white on gray')  
    if True == data['19']:
        window['-19-'].update( button_color='white on green')
    else:
        window['-19-'].update( button_color='white on gray')   
    if True == data['20']:
        window['-20-'].update( button_color='white on green')
    else:
        window['-20-'].update( button_color='white on gray')   
    if True == data['21']:
        window['-21-'].update( button_color='white on green')
    else:
        window['-21-'].update( button_color='white on gray')  
    if True == data['22']:
        window['-22-'].update( button_color='white on green')
    else:
        window['-22-'].update( button_color='white on gray')  
    if True == data['23']:
        window['-23-'].update( button_color='white on green')
    else:
        window['-23-'].update( button_color='white on gray')   
    if True == data['24']:
        window['-24-'].update( button_color='white on green')
    else:
        window['-24-'].update( button_color='white on gray')   
    if True == data['25']:
        window['-25-'].update( button_color='white on green')
    else:
        window['-25-'].update( button_color='white on gray')  
    if True == data['26']:
        window['-26-'].update( button_color='white on green')
    else:
        window['-26-'].update( button_color='white on gray')  
    if True == data['27']:
        window['-27-'].update( button_color='white on green')
    else:
        window['-27-'].update( button_color='white on gray')   
    if True == data['28']:
        window['-28-'].update( button_color='white on green')
    else:
        window['-28-'].update( button_color='white on gray')   
    if True == data['29']:
        window['-29-'].update( button_color='white on green')
    else:
        window['-29-'].update( button_color='white on gray')  
    if True == data['30']:
        window['-30-'].update( button_color='white on green')
    else:
        window['-30-'].update( button_color='white on gray')  
    if True == data['31']:
        window['-31-'].update( button_color='white on green')
    else:
        window['-31-'].update( button_color='white on gray')           

def main():
    global data
    global window
    invalidate_data()

    while True:             # Event Loop
        event, values = window.read()
        print(event, values)
        if event in (sg.WIN_CLOSED, 'Exit'):
            break
        elif event == '-hex2bin-':
            parseHex(values['-INPUT-'])
            update_data()
        elif event == '-0-':
            data['0'] = not data['0']
            update_data()
        elif event == '-1-':
            data['1'] = not data['1']
            update_data()
        elif event == '-2-':
            data['2'] = not data['2']
            update_data()
        elif event == '-3-':
            data['3'] = not data['3']
            update_data()
        elif event == '-4-':
            data['4'] = not data['4']
            update_data()
        elif event == '-5-':
            data['5'] = not data['5']
            update_data()
        elif event == '-6-':
            data['6'] = not data['6']
            update_data()
        elif event == '-7-':
            data['7'] = not data['7']
            update_data()   
        elif event == '-8-':
            data['8'] = not data['8']
            update_data()
        elif event == '-9-':
            data['9'] = not data['9']
            update_data()
        elif event == '-10-':
            data['10'] = not data['10']
            update_data()
        elif event == '-11-':
            data['11'] = not data['11']
            update_data()
        elif event == '-12-':
            data['12'] = not data['12']
            update_data()
        elif event == '-13-':
            data['13'] = not data['13']
            update_data()
        elif event == '-14-':
            data['14'] = not data['14']
            update_data()
        elif event == '-15-':
            data['15'] = not data['15']
            update_data() 
        elif event == '-16-':
            data['16'] = not data['16']
            update_data()
        elif event == '-17-':
            data['17'] = not data['17']
            update_data()
        elif event == '-18-':
            data['18'] = not data['18']
            update_data()
        elif event == '-19-':
            data['19'] = not data['19']
            update_data()
        elif event == '-20-':
            data['20'] = not data['20']
            update_data()
        elif event == '-21-':
            data['21'] = not data['21']
            update_data()
        elif event == '-22-':
            data['22'] = not data['22']
            update_data()
        elif event == '-23-':
            data['23'] = not data['23']
            update_data() 
        elif event == '-24-':
            data['24'] = not data['24']
            update_data()
        elif event == '-25-':
            data['25'] = not data['25']
            update_data()
        elif event == '-26-':
            data['26'] = not data['26']
            update_data()
        elif event == '-27-':
            data['27'] = not data['27']
            update_data()
        elif event == '-28-':
            data['28'] = not data['28']
            update_data()
        elif event == '-29-':
            data['29'] = not data['29']
            update_data()
        elif event == '-30-':
            data['30'] = not data['30']
            update_data()
        elif event == '-31-':
            data['31'] = not data['31']
            update_data()             
            

    window.close()

if __name__ == '__main__':
	main()