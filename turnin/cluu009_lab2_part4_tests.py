tests = [ {'description': 'PINA: 0x00, PINB: 35, PINC: 85 => PORTD: 0x1E',
    'steps': [ {'inputs': [('PINA',0x00), ('PINB', 35), ('PINC',85 ], 'iterations': 5 } ],
    'expected': [('PORTD',0x1E)],
    },
    {'description': 'PINA: 0x00, PINB: 56, PINC: 85 => PORTD: 0x22',
    'steps': [ {'inputs': [('PINA',0x04), ('PINB', 56), ('PINC', 85)], 'iterations': 5 } ],
    'expected': [('PORTD',0x22)],
    },
    ]
#watch = ['PORTB']

