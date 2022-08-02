#pragma once

#include "Node.h"

#include <stddef.h>

/**
 * @brief Функция для управления узлами в прямой последовательности
 */
bool manageNodes(Node* head, size_t nodesNum);

/**
 * @brief Функция для управления узлами в обратной последовательности
 */
bool manageNodesReverse(Node* tail);
