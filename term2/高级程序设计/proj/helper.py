from requests import post


def start_game(port=8090):
    return post(f'http://127.0.0.1:{port}/ajax/start/game/127.0.0.1').content

def get_state(n=1, port=8090):
    return [post(f'http://127.0.0.1:{port}/ajax/fetch/state/127.0.0.1').json() for i in range(n)]

def deploy_ant(row, col, type, port=8090):
    return post(f'http://127.0.0.1:{port}/ajax/deploy/ant/127.0.0.1', json={'pname': f'tunnel_{row}_{col}', 'ant': type})
