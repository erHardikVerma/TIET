def jug_puzzle():
    jug_3 = 0
    jug_4 = 0

    jug_3 = 3
    while jug_4 != 4:
        jug_4 += min(jug_3, 4 - jug_4)
        jug_3 -= min(jug_3, 4 - jug_4)

        if jug_4 == 4:
            jug_4 = 0

        if jug_3 == 0:
            jug_3 = 3

    while jug_4 != 2:
        jug_4 += min(jug_3, 2 - jug_4)
        jug_3 -= min(jug_3, 2 - jug_4)

    print("Final state: Jug 3 has", jug_3, "liters, Jug 4 has", jug_4, "liters.")

jug_puzzle()
